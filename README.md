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

## How It Works
The program reads the input file byte-by-byte and replaces consecutive
repeating characters with a single character followed by its count.
