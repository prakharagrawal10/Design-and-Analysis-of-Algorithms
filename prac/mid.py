import os

def copy_asm_files(directory):
    # Check if the directory exists
    if not os.path.exists(directory):
        print("Directory not found.")
        return
    
    # Open a new file to write the aggregated content
    with open("asm_content.txt", "w") as output_file:
        # Iterate through all files in the directory
        for filename in os.listdir(directory):
            if filename.endswith(".asm"):
                # Write the filename as a heading
                output_file.write(f"=== {filename} ===\n\n")
                # Read the content of the .asm file and write it to the output file
                with open(os.path.join(directory, filename), "r") as asm_file:
                    output_file.write(asm_file.read())
                output_file.write("\n\n")  # Add some space between files

# Call the function with the directory path
copy_asm_files(r"C:\Users\prakh\Downloads\micro lab codes")
