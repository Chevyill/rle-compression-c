#include <stdio.h>
#include <stdlib.h>



long Size(const char *input) {
    FILE *fpinput = fopen(input, "rb"); 
    if (fpinput == NULL) {
        printf(" Failed to open file %s\n", input);
        return -1; 
    }
    fseek(fpinput, 0, SEEK_END); 
    long FileSize = ftell(fpinput);  
    fclose(fpinput);           
    return FileSize;            
}

void compressor(const char *input, const char *output) {
    FILE *FPinput = fopen(input, "rb");  
    FILE *FPoutput = fopen(output, "wb");

    if (FPinput == NULL) {
        printf("Input file failed to open %s\n", input);
        return;
    }
    if (FPoutput == NULL) {
        printf("Output file failed to create %s\n", output);
        fclose(FPinput);
        return;
    }

    int currentChar = fgetc(FPinput);
    while (currentChar != EOF) {
        int counter = 1;
        int nextChar;

        do {
            nextChar = fgetc(FPinput);
            if (nextChar == currentChar && counter < 255) {
                counter++;
            } else {
                break;
            }
        } while (nextChar != EOF);

        fprintf(FPoutput, "%c%d", currentChar, counter);

        currentChar = nextChar;  
    }

    fclose(FPinput); 
    fclose(FPoutput); 
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];  
    const char *output = argv[2]; 

    long inputSize = Size(input);
    if (inputSize == -1) {
        return 1;
    }

    compressor(input, output);

    long outputSize = Size(output);
    if (outputSize == -1) {
        return 1;
    }

    double reducedAmt = ((double)(inputSize - outputSize) / inputSize) * 100;

    printf("Compression completed: %s -> %s\n", input, output);
    printf("The input file size is: %ld bytes, and the output file size is: %ld bytes\n", inputSize,     outputSize);
    printf("File size reduction is: %.2f%% - %s\n", reducedAmt,
           (reducedAmt < 38.10) ? "Below average" : "Above average");
    return 0;
}


