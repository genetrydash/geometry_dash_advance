import csv
import math

def load_csv_to_array(file_path):
    """Reads a CSV file and loads it into a 2D list."""
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        return [list(row) for row in reader]

def chunkify_to_1d(level_array, chunk_size=16):
    """Splits the level array into 16x16 chunks stored in a 1D list."""
    height = len(level_array)
    width = len(level_array[0])
    
    chunks = []
    
    # Number of chunks horizontally and vertically
    num_horizontal_chunks = (width + chunk_size - 1) // chunk_size
    num_vertical_chunks = (height + chunk_size - 1) // chunk_size
    
    for v_chunk in range(num_vertical_chunks):
        for h_chunk in range(num_horizontal_chunks):
            # Extract a single 16x16 chunk
            chunk = [
                level_array[row][h_chunk * chunk_size:(h_chunk + 1) * chunk_size]
                for row in range(v_chunk * chunk_size, min((v_chunk + 1) * chunk_size, height))
            ]
            # Pad chunk to 16x16 if necessary
            while len(chunk) < chunk_size:
                chunk.append(['0'] * chunk_size)  # Pad with zeros
            for row in chunk:
                while len(row) < chunk_size:
                    row.append('0')  # Pad row with zeros
            chunks.append(chunk)
    
    return chunks

def export_chunks_to_s_file(level_name, chunks, output_path):
    """Exports the chunks into a .s file."""
    with open(output_path, 'w') as file:
        file.write("@ Level Data Export\n")
        file.write("@ Each chunk is 16x16 blocks\n\n")
        file.write(".section .rodata\n")
        file.write(".align 2\n")
        file.write(f".global {level_name}_chunk_0\n")
        file.write(f".hidden {level_name}_chunk_0\n")
        for i, chunk in enumerate(chunks):
            file.write(f"{level_name}_chunk_{i}:")
            for row in chunk:
                # Convert each value to an integer string if not already numeric
                file.write("    .hword " + ", ".join(row) + "\n")
            file.write("\n")
            
def export_header_file(level_name, level_array, level_width, output_path):
    """Exports a header file with references to the first chunk and the level width."""
    rounded_width = math.floor(((level_width + 15) // 16 * 16) / 16)  # Round up to the nearest multiple of 16
    with open(output_path, 'w') as file:
        file.write("// Level Data Header\n")
        file.write(f"#define {level_name.upper()}_LEVEL_WIDTH {rounded_width}\n")
        file.write(f"#define TOTAL_BLOCKS {len(level_array) * len(level_array[0])}\n")
        file.write(f"extern const unsigned short {level_name}_chunk_0[TOTAL_BLOCKS];\n")

def main():
    level_name = "cantletgo"
    file_path = f"levels/{level_name}_.csv"  # Replace with your CSV file path
    output_s_path = f"levels/{level_name}.s"  # Output .s file
    output_h_path = f"levels/{level_name}.h"  # Output .h file
    
    level_array = load_csv_to_array(file_path)
    chunks = chunkify_to_1d(level_array, chunk_size=16)
    export_chunks_to_s_file(level_name, chunks, output_s_path)
    export_header_file(level_name, level_array, len(level_array[0]), output_h_path)
    
    print(f"Exported {len(chunks)} chunks to {output_s_path} and header to {output_h_path}")

if __name__ == "__main__":
    main()
