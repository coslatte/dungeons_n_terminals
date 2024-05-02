#include "animations.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

void animation_starting_combat()
{
    system("cls");
    for (size_t i = 0; i < 4; i++)
    {
        char *dot = "";
        for (size_t j = 0; j < 3; j++)
        {
            if (j == 0)
                dot = ".";
            if (j == 1)
                dot = "..";
            if (j == 2)
                dot = "...";
            printf("Comenzando el combate%s <---", dot);
            Sleep(100);
            system("cls");
        }
    }
}