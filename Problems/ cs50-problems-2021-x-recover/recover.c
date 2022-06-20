#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int bulk = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Couldn’t open file.\n");
        return 1;
    }
    
    uint8_t buffer[bulk]; 
    
    //buffer to read bulks from the file
    
    int cnt = 0; 
    char filename[8]; 
    
    //file name 000.jpg each character takes 1 bit and terminating character so size = 8
    
    FILE *img = malloc(5); 
    
    // open a file pointer to be read throughout the whole loop and allocate to it memory to not be dangling pointer
    
    while (fread(buffer, sizeof(bulk), 1, input))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if ((buffer[3] & 0xf0) == 0xe0)
            {
                if (cnt == 0)
                {
                    sprintf(filename, "%03i.jpg", cnt);
                    cnt++;
                    img = fopen(filename, "w");
                }
                else
                {
                    fclose(img);
                    sprintf(filename, "%03i.jpg", cnt);
                    cnt++;
                    img = fopen(filename, "w");
                }
                
                fwrite(buffer, sizeof(bulk), 1, img);
            }
        }
        else
        {
            if (cnt != 0)
            {
                fwrite(buffer, sizeof(bulk), 1, img);
            }
        }
    }
    
    // free allocated memory and close files
    
    free(img);
    fclose(img);
    fclose(input);
    
    return 0;
}