#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
void tokenize(char *str, char *buf[], int n, char *delim)
{

    char *tok = strtok(str, delim);
    int ntoks = 0;
    while (tok != NULL)
    {

        if (ntoks == n)
            break;

        buf[ntoks++] = tok;

        tok = strtok(NULL, delim);
    }
}

int getHex(char *hex)
{

    long val = strtol(hex, NULL, 16);

    return (int)val;
}

void hexdecode(char *str)
{
    int ct = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '%')
            ct++;
    }
    if (ct)
    {
        char new_str[strlen(str) + 1 - ct * 3 + ct];
        new_str[0] = '\0';

        int ind = 0;

        char hexcode[3];

        while (ind < strlen(str))
        {

            if (str[ind] == '%' && str[ind + 1] && str[ind + 2])
            {
                strncpy(hexcode, &str[ind + 1], 2);
                hexcode[2] = '\0';
                char escapedChar = (char)getHex(hexcode);
                strncat(new_str, &escapedChar, 1);
                ind += 3;
            }
            else
            {
                strncat(new_str, &str[ind], 1);
                ind++;
            }
        }
        strcpy(str, new_str);
    }
}

int main(int argc, char **argv)
{

    char p[] = "";

    hexdecode(p);

    printf("%s", p);
}