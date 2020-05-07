#include <stdio.h>

#include "../../cs50.h"

int main(void)
{
    printf("hello, world\n");
    char* name = get_string("what is your name?\n");
    printf("hello, %s\n", name);
}
