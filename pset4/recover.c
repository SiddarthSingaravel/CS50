#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // checking only for two arguments
    if (argc != 2)
    {
        //writing or printing it to file
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    // Saving file name which is in argv[1]
    char *infile = argv[1];

    // open input file
    FILE *f1 = fopen(infile, "r");
    if (f1 == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int imageCount = 0;

    char filename[8];
    FILE *f2 = NULL;

    while (true)
    {
        // read a block of the card.raw
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, f1);

        // breaks out of loop when we reach end of card.raw
        if (bytesRead == 0 && feof(f1))
        {
            break;
        }

        // Finding for JPEG
        bool containsJpegHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // if we found a yet another JPEG, we must close the previous file
        if (containsJpegHeader && f2 != NULL)
        {
            fclose(f2);
            imageCount++;
        }

        // Opening a jpeg file for writing data till we encounter a new jpeg one
        if (containsJpegHeader)
        {
            sprintf(filename, "%03i.jpg", imageCount);
            f2 = fopen(filename, "w");
        }

        // writing
        if (f2 != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, f2);
        }
    }

    // closing last jpeg one f2
    fclose(f2);

    // close f1
    fclose(f1);

    // recovered 49 jpeg files in total
    return 0;
}