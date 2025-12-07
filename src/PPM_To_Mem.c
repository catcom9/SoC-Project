#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

//Works with PPM files that gimp exports.

#define PPM_MAGIC_NUMBER "P6"
#define PPM_MAGIC_NUMBER_SIZE 2
#define MAX_IMAGE_ROW 480
#define MAX_IMAGE_COL 680
#define MAX_COLOUR_VALUE 255

#define MASK 0xF0

#define BUFFER_SIZE 60

char decToHex[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};


int main (int argc, char **argv){
    char buffer[BUFFER_SIZE];
    int imgRows, imgCols, maxColour;


    if (argc == 0){
        printf("No input file\n");
        return EXIT_FAILURE;
    }

    FILE* ppm_file = fopen(argv[1], "rb");

    if(!ppm_file){
        printf("Cant open file\n");
        return EXIT_FAILURE;
    }

    fread(buffer, 1, 3, ppm_file);
    buffer[2] = '\0';


    //Check if file is a PPM file by using its magic number at the start
    if(strcmp(buffer, PPM_MAGIC_NUMBER) != 0){
        printf("Not a PPM file\n");
        fclose(ppm_file);
        return EXIT_FAILURE;
    }

    while (1){
        static int feildCount = 0;
        fgets(buffer, BUFFER_SIZE, ppm_file);
        //Check if its a comment if it is move on.
        if (buffer[0] == '#'){
            continue;
        }

        //If it begins with a number its something that matters
        if ((buffer[0] - 48) <= 9 && (buffer[0] - 48) >= 0){
            //First Feild is 0 it means we are on the image size feild
            if(feildCount == 0){
                imgCols = atoi(buffer);
                strtok(buffer, " ");
                imgRows = atoi(strtok(NULL, " "));
                feildCount++;
            } else if(feildCount == 1){
                maxColour = atoi(buffer);
                if (maxColour != MAX_COLOUR_VALUE){
                    printf("Colour value miss match\n");
                    fclose(ppm_file);
                    return EXIT_FAILURE;
                }
                break;
            }
        }
    }

    FILE* outputFile = fopen("output.mem", "wb");

    if (!outputFile){
        printf("Cant open output file\n");
        fclose(ppm_file);
        return EXIT_FAILURE;
    }

    int totalPixels = imgRows * imgCols;

    for(int i = 0; i != totalPixels; i++){
        fread(buffer, 1, 3, ppm_file);
        for(int y = 0; y != 3; y++){
            char hexChar = decToHex[(buffer[y] & MASK) >> 4];
            fputc(hexChar, outputFile);
        }
        fputc(' ', outputFile);
    }


    fclose(outputFile);
    fclose(ppm_file);
    return 0;




}
