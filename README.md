# Run-Length Encoding (RLE) Compression Tool

A command-line file compression program written in C that implements
Run-Length Encoding (RLE) to reduce file size by compressing consecutive
repeating characters.

This project demonstrates low-level file handling, binary I/O, and
algorithmic problem solving in C.

## Features
- Compresses files using Run-Length Encoding (RLE)
- Supports binary and text files
- Limits run length to 255 to fit within a single byte
- Calculates and reports compression percentage
- Graceful handling of file I/O errors

## Example
AAAAABB → A5B2

## Usage

### Compile the program
gcc rle_compress.c -o rle_compress

Run the compressor
./rle_compress input.txt output.rle

Sample Output
Compression completed: input.txt -> output.rle
The input file size is: 1200 bytes, and the output file size is: 620 bytes
File size reduction is: 48.33% - Above average
