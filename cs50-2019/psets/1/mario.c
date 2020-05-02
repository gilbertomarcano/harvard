#include <stdio.h>

int main(void)
{
    int height;
    printf("Height: ");
    scanf("%i", &height);

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