#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "functions.h"

int main()
{
    char input = read_console();
    printf(">>> %c\n", input);
    Sleep(3000);
    return EXIT_SUCCESS;
}