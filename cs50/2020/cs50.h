#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string(const char* prompt)
{
    char buffer[256];
    printf("%s", prompt);
    scanf("%[^\n]", buffer);
    // used to clear the buffer
    // and accept the next string
    while (getchar() != '\n');


    char* string = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(string, buffer);

    return string;
}

long get_long(const char*prompt)
{
    while (1)
    {
        const char* str = get_string(prompt);
        char* end;
        long integer = strtol(str, &end, 10);


        if (!*end)
            return integer;
    }
}

int get_int(const char* prompt)
{
    return (int) get_long(prompt);
}



char* ltoa(long val)
{
    char buffer[256];

    sprintf(buffer, "%li", val);
    char* string = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(string, buffer);

    return string;
}

char* ultoa(unsigned long val)
{
    char buffer[256];

    sprintf(buffer, "%lu", val);
    char* string = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(string, buffer);

    return string;
}

char* itoa(int val)
{
    char buffer[256];

    sprintf(buffer, "%i", val);
    char* string = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(string, buffer);

    return string;
}

char* utoa(unsigned int val)
{
    char buffer[256];

    sprintf(buffer, "%i", val);
    char* string = (char*) malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(string, buffer);

    return string;
}