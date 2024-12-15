import csv
import sys

def load_csv_to_array(file_path):
    """Reads a CSV file and loads it into a 2D list."""
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        return [list(row) for row in reader]

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
        current_value = flat_level[i]
        if current_value == prev_value:
            count += 1
        else:
            compressed.append((prev_value, count))
            prev_value = current_value
            count = 1
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
        file_path = f"levels/{level_name}_{layer}.csv" # Replace with your CSV file path
        output_s_path = f"levels/{level_name}_{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}_{layer}.h"  # Output .h file
        
        level_array = load_csv_to_array(file_path)
        compressed = rle_compress_level(level_array)
        export_compressed_to_s_file(level_name, layer, compressed, output_s_path)
        export_header_file(level_name, layer, level_array, compressed, output_h_path)

        layer = f"l2"
        file_path = f"levels/{level_name}_{layer}.csv" # Replace with your CSV file path
        output_s_path = f"levels/{level_name}_{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}_{layer}.h"  # Output .h file
               
        level_array = load_csv_to_array(file_path)
        compressed = rle_compress_level(level_array)
        export_compressed_to_s_file(level_name, layer, compressed, output_s_path)
        export_header_file(level_name, layer, level_array, compressed, output_h_path)
        
        print(f"Exported compressed data to {output_s_path} and header to {output_h_path}")

if __name__ == "__main__":
    main()
