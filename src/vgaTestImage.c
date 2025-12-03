#include <stdio.h>

#define FILENAME "VGA_ColourFill.mem"
#define HEX_COLOUR "F "

#define H_SIZE 640
#define V_SIZE 480


int main(){
    int pixelCount = 0;
    FILE* filepointer = fopen(FILENAME, "w");

    for (int y = 0; y != V_SIZE; y++){
        for(int x = 0; x != H_SIZE; x++){
            fprintf(filepointer, HEX_COLOUR);
        }
        fprintf(filepointer, "\n");
    }

    fclose(filepointer);
    return 0;
}
