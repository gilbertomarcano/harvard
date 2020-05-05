/*
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.

   #  #
  ##  ##
 ###  ###
####  ####

The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.
*/

#include <stdio.h>

#include "../../cs50.h"

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);


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