#include <stdio.h>

#include "../../cs50.h"

int main(void)
{
    // Get the height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Iterate over the i'th rows and the j'th columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height * 2 + 1; j++)
        {
            if (j < height - 1 - i|| j > height + 1 + i|| j == height)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
