import json
import sys
import os

def rgb888_to_rgb555_24bit(rgb888):
    """
    Converts a 24-bit integer (RGB888) to a 16-bit integer (RGB555).
    
    Parameters:
    - rgb888: 24-bit integer representing an RGB888 color.
    
    Returns:
    - 16-bit integer representing an RGB555 color.
    """
    # Extract RGB888 components
    r = (rgb888 >> 16) & 0xFF  # Extract red (highest byte)
    g = (rgb888 >> 8) & 0xFF   # Extract green (middle byte)
    b = rgb888 & 0xFF          # Extract blue (lowest byte)
    
    # Convert to RGB555
    r_5 = (r >> 3) & 0x1F  # 5 bits for red
    g_5 = (g >> 3) & 0x1F  # 5 bits for green
    b_5 = (b >> 3) & 0x1F  # 5 bits for blue
    
    # Combine into a 16-bit BGR555 value
    rgb555 = (b_5 << 10) | (g_5 << 5) | r_5
    
    return rgb555

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
            byte_counter = 0
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
                    byte_counter += 8
                    if gid == 3: # COLOR TRIGGER
                        channel = 'BG'
                        color = 0
                        frames = 0
                        copy = False
                        copy_channel = 'BG'

                        try: 
                            properties = obj['properties']
                            for prop in properties:
                                if prop['name'] == 'Channel':
                                    channel = prop['value']
                                elif prop['name'] == 'Color':
                                    color = int(prop['value'][3:], 16)
                                elif prop['name'] == 'Frames':
                                    frames = int(prop['value'])
                                elif prop['name'] == 'Copy color':
                                    copy = bool(prop['value'])
                                elif prop['name'] == 'Copy from channel':
                                    copy_channel = prop['value']

                        except Exception:
                            raise Exception(f"Encountered color trigger without attributes on pos {x/16}, {y/16}.")
                        
                        channel_id = 0

                        possible_channels = ["BG", "GROUND", "OBJ", "LINE", "1", "2", "3", "4"]

                        possible_copy_channels = ["BG", "GROUND", "OBJ", "LINE", "P1", "P2", "1", "2", "3", "4"]

                        if channel not in possible_channels:
                            raise Exception(f"Encountered invalid color channel: {channel}, on pos {x/16}, {y/16}. Must be one of the following: BG, GROUND, OBJ, LINE, 1, 2, 3, 4.") 

                        if channel == "BG":
                            channel_id = 4
                        elif channel == "GROUND":
                            channel_id = 5
                        elif channel == "OBJ":
                            channel_id = 6
                        elif channel == "LINE":
                            channel_id = 7
                        else:
                            channel_id = int(channel) - 1
                            
                        copy_channel_id = 0
                        if copy:
                            if copy_channel not in possible_copy_channels:
                                raise Exception(f"Encountered invalid copy color channel: {copy_channel}, on pos {x/16}, {y/16}. Must be one of the following: BG, GROUND, OBJ, LINE, P1, P2, 1, 2, 3, 4.") 
                            
                            if copy_channel == "BG":
                                copy_channel_id = 4
                            elif copy_channel == "GROUND":
                                copy_channel_id = 5
                            elif copy_channel == "OBJ":
                                copy_channel_id = 6
                            elif copy_channel == "LINE":
                                copy_channel_id = 7
                            elif copy_channel == "P1":
                                copy_channel_id = 8
                            elif copy_channel == "P2":
                                copy_channel_id = 9
                            else:
                                copy_channel_id = int(channel) - 1
                            

                        color_bgr555 = rgb888_to_rgb555_24bit(color)
                    
                        out_file.write(f"   .hword {hex((frames << 3) | channel_id)}\n")
                        out_file.write(f"   .hword {hex(color_bgr555)}\n")
                        out_file.write(f"   .hword {hex((copy_channel_id << 1) | copy)}\n")
                        out_file.write(f"   .hword 0x0000\n")
                        byte_counter += 8
                    else:
                        h_flip = False
                        v_flip = False
                        enable_rotation = False
                        rotation = 0
                        try: 
                            properties = obj['properties']
                            for prop in properties:
                                if prop['name'] == 'hflip':
                                    h_flip = bool(prop['value'])
                                elif prop['name'] == 'vflip':
                                    v_flip = bool(prop['value'])
                                elif prop['name'] == 'enable rotation':
                                    enable_rotation = bool(prop['value'])
                                elif prop['name'] == 'rotation angle':
                                    rotation = int(prop['value'])
                        except Exception:
                            pass
                        out_file.write(f"   .hword {hex((enable_rotation << 2) | (h_flip << 1) | v_flip)}\n")
                        out_file.write(f"   .hword {int(rotation / 360.0 * 65536)}\n")
                        byte_counter += 4

                out_file.write(f"   .byte 0xff\n")
                byte_counter += 1
                print(f"Object data size: {byte_counter} B")
                print(f"Exported object data to {output_s_path} and {output_h_path}")
            with open(output_h_path, 'w') as file:
                file.write("// Sprite data Header\n")
                file.write(f"#define {level_name.upper()}_TOTAL_SPR {counter}\n")
                file.write(f"extern const unsigned short {level_name}_spr_data[({level_name.upper()}_TOTAL_SPR * 2) + 1];\n")

            return len(objects) * 8 + 1
    
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

        if current_value < 0: current_value = 0

        if current_value == prev_value:
            count += 1
        else:
            compressed.append((prev_value, count - 1))
            prev_value = current_value
            count = 1
        
        
    compressed.append((prev_value, count - 1))  # Add the last run

    return compressed

def pack_rle_data(compressed):
    """Packs RLE compressed data (value and count pairs) into a tight bitstream."""
    bitstream = 0  # Buffer to hold packed bits
    bit_count = 0  # Number of bits currently in the buffer
    packed_data = []  # Output list for packed 32-bit words
    for value, count in compressed:
        # Pack 16-bit value
        bitstream = (bitstream << 16) | value
        bit_count += 16
        
        if count == 0:
            count_size = 1
        else:
            count_size = count.bit_length()

        # Pack count size in bits
        bitstream = (bitstream << 4) | count_size
        bit_count += 4

        # Pack dynamic sized count
        bitstream = (bitstream << count_size) | count
        bit_count += count_size

        # Flush full 32-bit words to the output
        while bit_count >= 32:
            packed_data.append((bitstream >> (bit_count - 32)) & 0xFFFFFFFF)
            bit_count -= 32

    # Handle remaining bits
    if bit_count > 0:
        packed_data.append((bitstream << (32 - bit_count)) & 0xFFFFFFFF)

    return packed_data  # Return packed data

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
        for value in compressed:
            file.write(f"    .word {"0b{:032b}".format(value)} @ {"0x{:08x}".format(value)}\n")
            
def export_header_file(level_name, layer, level_array, compressed, output_path):
    """Exports a header file with references to the first chunk and the level width."""
    rle_size = len(compressed) * 4  # Each RLE entry consists of a value and a count
    with open(output_path, 'w') as file:
        file.write("// Level Data Header\n")
        file.write(f"#define {level_name.upper()}_{layer}_TOTAL_BLOCKS {len(level_array) * len(level_array[0])}\n")
        file.write(f"#define {level_name.upper()}_{layer}_RLE_DATA_SIZE {rle_size}\n")
        file.write(f"extern const unsigned short {level_name}_{layer}_level_data[{level_name.upper()}_{layer}_RLE_DATA_SIZE];\n")

def export_includes_h(levels):
    with open("levels/includes.h", 'w') as file:
        level_counter = 0
        file.write("#pragma once\n\n")
        file.write("#include <tonc.h>\n\n")
        for level_name in levels:
            file.write(f"// {level_name}\n")
            file.write(f"#define {level_name}_ID {level_counter}\n\n")
            file.write(f"#include \"{level_name}/l1.h\"\n")
            file.write(f"#include \"{level_name}/l2.h\"\n")
            file.write(f"#include \"{level_name}/SP.h\"\n")
            file.write(f"#include \"{level_name}/properties.h\"\n\n")

            level_counter += 1

        file.write(f"#define LEVEL_COUNT {level_counter}\n")
        file.write(f"extern const u16 *level_defines[][4];\n")
        file.write(f"extern const u8 *level_names[];\n")
    
    with open("levels/includes.c", 'w') as file:
        file.write(f"#include \"includes.h\"\n")
        file.write(f"const u16 *level_defines[][4] = {{\n")
        for level_name in levels:
            file.write(f"   {{ {level_name}_l1_level_data, {level_name}_l2_level_data, {level_name}_spr_data, {level_name}_properties }},\n")
        
        file.write("};\n")

        file.write(f"const u8 *level_names[] = {{\n")
        for level_name in levels:
            file.write(f"   {level_name}_name,\n")
        
        file.write("};\n")



def export_properties_to_h(level_name, output_path_h, output_path_c, json_file_path, level_array):
    level_height = len(level_array)
    # Load JSON
    with open(json_file_path, 'r') as f:
        json_data = json.load(f)
    try: 
        properties = json_data["properties"]
        bg_color = ""
        g_color = ""
        gamemode = 0
        menu_name = level_name
        speed = 1
        song = "STEREOMA"
        for prop in properties:
            if prop['name'] == 'BG':
                bg_color = int(prop['value'][3:], 16)
            elif prop['name'] == 'GROUND':
                g_color = int(prop['value'][3:], 16)
            elif prop['name'] == 'Gamemode':
                gamemode = int(prop['value'])
            elif prop['name'] == 'Speed':
                speed = prop['value']
            elif prop['name'] == 'Level name':
                menu_name = prop['value']
            elif prop['name'] == 'Song':
                song = prop['value']
        # BG color
        if bg_color != "":
            bg_color_bgr555 = rgb888_to_rgb555_24bit(bg_color)
        else:
            bg_color_bgr555 = rgb888_to_rgb555_24bit(0x0000ff)

        # Ground color
        if g_color != "":
            g_color_bgr555 = rgb888_to_rgb555_24bit(g_color)
        else:
            g_color_bgr555 = rgb888_to_rgb555_24bit(0x0000ff)
    except Exception:
        raise Exception(f"Level {level_name} doesn't have attributes. To see the level attributes, go to \"Map\" on tiled and then \"Map attributes\"")

    with open(output_path_c, 'w') as file:
        file.write(f"#include \"soundbank.h\"\n")
        file.write(f"// {level_name} properties\n")

        file.write(f"const unsigned short {level_name}_properties[] = {{\n")
        file.write(f" /*BG color*/      {hex(bg_color_bgr555)},\n")
        file.write(f" /*GROUND color*/  {hex(g_color_bgr555)},\n")
        file.write(f" /*gamemode*/      {gamemode},\n")
        file.write(f" /*speed*/         {speed},\n")
        file.write(f" /*level height*/  {level_height},\n")
        file.write(f" /*song*/          MOD_{song},\n")
        file.write(f"}};\n\n")

        file.write(f"const unsigned char {level_name}_name[] = {{\n")
        file.write(f"   \"{menu_name.upper()}\"\n")
        file.write(f"}};\n")

    with open(output_path_h, 'w') as file:
        file.write("#pragma once\n\n")
        file.write(f"// {level_name} properties\n")

        file.write(f"extern const unsigned short {level_name}_properties[];\n")
        file.write(f"extern const unsigned char {level_name}_name[];\n")


def main():
    original_size_list = []
    size_list = []
    total_total_size = 0
    for level_name in sys.argv[1:]:
        total_size = 0

        print(f"---{level_name}---")
        if not os.path.exists(f"levels/{level_name}"):
            os.makedirs(f"levels/{level_name}")

        layer = "l1"
        file_path = f"levels/{level_name}.json" # JSON file
        output_s_path = f"levels/{level_name}/{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}/{layer}.h"  # Output .h file
        level_array = load_json_to_array(file_path, layer)
        unpacked = rle_compress_level(level_array)
        original_size_list.append(len(unpacked) * 4)
        compressed = pack_rle_data(unpacked)
        size_list.append(len(compressed) * 4)
        total_size += len(compressed) * 4

        print(f"Layer {layer} size: {len(compressed) * 4} B")
        export_compressed_to_s_file(level_name, layer, compressed, output_s_path)
        export_header_file(level_name, layer, level_array, compressed, output_h_path)
        print(f"Exported compressed data to {output_s_path} and header to {output_h_path}")

        layer = f"l2"
        output_s_path = f"levels/{level_name}/{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}/{layer}.h"  # Output .h file
               
        level_array = load_json_to_array(file_path, layer)
        unpacked = rle_compress_level(level_array)
        original_size_list.append(len(unpacked) * 4)
        compressed = pack_rle_data(unpacked)
        size_list.append(len(compressed) * 4)
        total_size += len(compressed) * 4

        print(f"Layer {layer} size: {len(compressed) * 4} B")
        export_compressed_to_s_file(level_name, layer, compressed, output_s_path)
        export_header_file(level_name, layer, level_array, compressed, output_h_path)
        print(f"Exported compressed data to {output_s_path} and header to {output_h_path}")

        layer = f"SP"
        output_s_path = f"levels/{level_name}/{layer}.s"  # Output .s file
        output_h_path = f"levels/{level_name}/{layer}.h"  # Output .h file

        total_size += export_objects_to_assembly(file_path, level_name, layer, output_s_path, output_h_path)

        output_h_path = f"levels/{level_name}/properties.h"  # Output .h file
        output_c_path = f"levels/{level_name}/properties.c"  # Output .c file

        export_properties_to_h(level_name, output_h_path, output_c_path, file_path, level_array)

        
        print(f"{level_name} TOTAL size: {total_size} B\n")
        total_total_size += total_size

    export_includes_h(sys.argv[1:])

    print("\nCOMPRESSION RESULTS")
    index = 0
    for level_name in sys.argv[1:]:
        print(f"---{level_name}---")
        orig = original_size_list[index]
        new = size_list[index]
        if orig > new:
            ratio = (1 - (new/orig)) * 100
        else:
            ratio = -((1 - (orig/new)) * 100)
        print(f"L1 - Original {orig} B | Compressed {new} B -> Compression ratio: {ratio}%")
        index += 1

        orig = original_size_list[index]
        new = size_list[index]
        if orig > new:
            ratio = (1 - (new/orig)) * 100
        else:
            ratio = -((1 - (orig/new)) * 100)

        print(f"L2 - Original {orig} B | Compressed {new} B -> Compression ratio: {ratio}%")
        index += 1

    print(f"\nAll levels TOTAL size: {total_total_size} B")
if __name__ == "__main__":
    main()
