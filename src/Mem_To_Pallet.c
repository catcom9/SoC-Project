#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PALLET 1000
#define NUM_OF_PIXELS 640 * 480

#define COLOR_PALLET_SIZE 16


const char decToHex[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};


// Input, NumOfColors
int main (int argc, char **argv){
    uint32_t pallet[COLOR_PALLET_SIZE] = {0};
    uint16_t current_pallet_size = 0;

    if (argc <= 0){
        printf("No input file provided!\n");
        return EXIT_FAILURE;
    }


    FILE* input_File = fopen(argv[1], "rb");
    if (!input_File){
        printf("Cant open file!\n");
        return EXIT_FAILURE;
    }

    FILE* output_File = fopen("output.mem", "wb");
    if (!output_File) {
        printf("Cant open output file!\n");
        return EXIT_FAILURE;
    }

    FILE* pallet_File = fopen("pallet.mem", "wb");
    if (!pallet_File) {
        printf("Cant open pallet file!\n");
        return EXIT_FAILURE;
    }


    for(int i = 0; i != NUM_OF_PIXELS; i++){
        uint32_t packed_hex = 0;
        for(int x = 0; x != 3; x++){
            int next_char = fgetc(input_File);
            if(next_char == EOF){
                printf("End of file reached. Shouldnt have happend?\n");
                return EXIT_FAILURE;
            }
            packed_hex |= (uint32_t)((char)next_char) << (8 * x);
        }
        fgetc(input_File);

        uint16_t pallet_index = 0;
        uint8_t not_in_pallet = 1;
        for(int i = 0; i != current_pallet_size; i++) {
            if(packed_hex == pallet[i]){
                pallet_index = i;
                not_in_pallet = 0;
                break;
            }
        }

        if (not_in_pallet == 1){
            pallet[current_pallet_size] = packed_hex;
            pallet_index = current_pallet_size;
            current_pallet_size++;
        }

        fputc(decToHex[pallet_index], output_File);
        fputc(' ', output_File);

    }

    char buffer[5];
    buffer[3] = '\n';
    buffer[4] = '\0';

    for(uint8_t i = 0; i != COLOR_PALLET_SIZE; i++){
        buffer[0] = (char)pallet[i];
        buffer[1] = (char)(pallet[i] >> 8);
        buffer[2] = (char)(pallet[i] >> 16);
        fputs(buffer, pallet_File);
        fputc(' ', pallet_File);
    }

}





