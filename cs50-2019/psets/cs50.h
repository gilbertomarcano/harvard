#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* get_string(const char* prompt)
{
    char buffer[256];
    printf("%s", prompt);
    scanf("%[^\n]", buffer);
    // used to clear the buffer 
    // and accept the next string 
    while (getchar() != '\n');


    char* string = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(string, buffer);

    // used to clear the buffer 
    // and accept the next string 

    return string;
}

long get_long(const char* prompt)
{
    while (1)
    {
        const char* str = get_string(prompt);
        char* end;
        int integer = strtol(str, &end, 10);

        if (!*end)
            return integer;
    }
}

int get_int(const char* prompt)
{
    return (int) get_long(prompt);
}