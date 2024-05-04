#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char read_console()
{
    char *buf = (char *)malloc(10 * sizeof(char));
    scanf("%c", buf);
    char output = buf[0];
    free(buf);
    return output;
}