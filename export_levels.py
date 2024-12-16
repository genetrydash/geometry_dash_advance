import json
import sys
import struct

def load_json_to_array(file_path, layer_name):
    """Reads a JSON file and extracts the array at the path 'layers -> data'."""
    with open(file_path, 'r') as file:
        # Parse the JSON file
        json_data = json.load(file)

        for layer in json_data['layers']:
            if layer['name'] == layer_name:
                width = layer['width']
                data = layer['data']
                
                # Convert data to 2D array
                return [data[i:i+width] for i in range(0, len(data), width)]
    
    # If layer not found, return None
    return None

def export_objects_to_assembly(json_file_path, level_name, layer_name, output_s_path, output_h_path):
    # Load JSON
    with open(json_file_path, 'r') as f:
        json_data = json.load(f)
    
    # Find the layer by name
    for layer in json_data['layers']:
        if layer['name'] == layer_name and 'objects' in layer:
            objects = layer['objects']
            counter = 0
            sorted_objects = sorted(objects, key=lambda obj: (obj['x'], obj['y']))
            
            # Open the output file for writing
            with open(output_s_path, 'w') as out_file:
                # Write assembly data for each object
                out_file.write("@ Sprite Data Export\n")
                out_file.write("\n")
                out_file.write(".section .rodata\n")
                out_file.write(".align 2\n")
                out_file.write(f".global {level_name}_spr_data\n")
                out_file.write(f".hidden {level_name}_spr_data\n")
                out_file.write(f"{level_name}_spr_data:\n")
                for obj in sorted_objects:
                    counter += 1
                    x = int(obj['x'])  # Convert to int
                    y = int(obj['y'])  # Convert to int
                    gid = int(obj['gid']) - 513  # Convert to int
                    
                    # Write the assembly instructions
                    out_file.write(f"@ Object {counter}\n")
                    out_file.write(f"   .word {hex(x)}\n")
                    out_file.write(f"   .hword {hex(y)}\n")
                    out_file.write(f"   .hword {hex(gid)}\n")
                print(f"Objects exported to {output_s_path}")
                out_file.write(f"   .byte 0xff\n")
            with open(output_h_path, 'w') as file:
                file.write("// Sprite data Header\n")
                file.write(f"#define {level_name.upper()}_TOTAL_SPR {counter}\n")
                file.write(f"extern const unsigned int {level_name}_spr_data[({level_name.upper()}_TOTAL_SPR * 2) + 1];\n")

            return
    
    # If layer not found or doesn't contain objects, raise an error
    raise ValueError(f"Layer '{layer_name}' not found or does not contain objects.")
    
def rle_compress_level(level_array):
    """Compresses the level array using Run-Length Encoding (RLE) across the entire level, joining columns sequentially."""
    compressed = []
    flat_level = []

    # Flatten the level array column by column
    for col in range(len(level_array[0])):
        for row in range(len(level_array)):
            flat_level.append(level_array[row][col])

    # Perform RLE compression on the flattened array
    count = 1
    prev_value = flat_level[0]
    for i in range(1, len(flat_level)):
        current_value = flat_level[i] - 1
        if current_value == prev_value:
            count += 1
        else:
            compressed.append((prev_value, count))
            prev_value = current_value
            count = 1
        
        if prev_value == -1: prev_value = 0
    compressed.append((prev_value, count))  # Add the last run

    return compressed

def export_compressed_to_s_file(level_name, layer, compressed, output_path):
    """Exports the compressed level data into a .s file."""
    with open(output_path, 'w') as file:
        file.write("@ Level Data Export\n")
        file.write("@ Compressed using RLE\n\n")
        file.write(".section .rodata\n")
        file.write(".align 2\n")
        file.write(f".global {level_name}_{layer}_level_data\n")
        file.write(f".hidden {level_name}_{layer}_level_data\n")
        file.write(f"{level_name}_{layer}_level_data:\n")
        for value, count in compressed:
            file.write(f"    .hword {value}\n    .hword {count}    @ Value {value} repeats {count} times\n")
            
def export_header_file(level_name, layer, level_array, compressed, output_path):
    """Exports a header file with references to the first chunk and the level width."""
    level_height = len(level_array)  # Round up to the nearest multiple of 16
    rle_size = len(compressed) * 4  # Each RLE entry consists of a value and a count
    with open(output_path, 'w') as file:
        file.write("// Level Data Header\n")
        file.write(f"#define {level_name.upper()}_LEVEL_HEIGHT {level_height}\n")
        file.write(f"#define {level_name.upper()}_{layer}_TOTAL_BLOCKS {len(level_array) * len(level_array[0])}\n")
        file.write(f"#define {level_name.upper()}_{layer}_RLE_DATA_SIZE {rle_size}\n")
        file.write(f"extern const unsigned short {level_name}_{layer}_level_data[{level_name.upper()}_{layer}_RLE_DATA_SIZE];\n")

def main():
    for level_name in sys.argv[1:]:
        layer = "l1"
        file_path = f"levels/{level_name}.json" # Replace with your CSV file path
        output_s_path = f"levels/{level_name}_{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}_{layer}.h"  # Output .h file
        
        level_array = load_json_to_array(file_path, layer)
        print(level_array)
        compressed = rle_compress_level(level_array)
        export_compressed_to_s_file(level_name, layer, compressed, output_s_path)
        export_header_file(level_name, layer, level_array, compressed, output_h_path)

        layer = f"l2"
        file_path = f"levels/{level_name}.json" # Replace with your CSV file path
        output_s_path = f"levels/{level_name}_{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}_{layer}.h"  # Output .h file
               
        level_array = load_json_to_array(file_path, layer)
        compressed = rle_compress_level(level_array)
        export_compressed_to_s_file(level_name, layer, compressed, output_s_path)
        export_header_file(level_name, layer, level_array, compressed, output_h_path)

        layer = f"SP"
        output_s_path = f"levels/{level_name}_{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}_{layer}.h"  # Output .h file
        export_objects_to_assembly(file_path, level_name, layer, output_s_path, output_h_path)
        
        print(f"Exported compressed data to {output_s_path} and header to {output_h_path}")

if __name__ == "__main__":
    main()
