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

void game_text_intro()
{
    char msg1[] = "Hace no se cuanto tiempo (3000 a.c aprox), un heroe se adentraba en unas penumbrosas catacumbas  \n";
    char msg2[] = "de Nuevo Londo (si, haganse la idea que esto es en alguna parte del lore de Dark Souls). Su prin- \n";
    char msg3[] = "cipal objetivo era vencer a las temerosas bestias que yacian dentro de semejante lugar. Justo aqui\n";
    char msg4[] = "es cuando nuestro importante brujo que guiaba las andazas de nuestro heroe (tu), se responsabili- \n";
    char msg5[] = "za por la salud del joven guerrero y su victoria al vencer al mal.\n";

    // animation_of_decode(msg1);
    // animation_of_decode(msg2);
    // animation_of_decode(msg3);
    // animation_of_decode(msg4);
    // animation_of_decode(msg5);

    printf(msg1);
    Sleep(5000);
    printf(msg2);
    Sleep(5000);
    printf(msg3);
    Sleep(5000);
    printf(msg4);
    Sleep(5000);
    printf(msg5);
    Sleep(5000);
    system("cls");

    Sleep(1000);

    printf(
        "Tus controles para moverte son:\n"
        "       ---Movimiento---        \n"
        "          W: arriba            \n"
        "          S: abajo             \n"
        "          A: izquierda         \n"
        "          D: derecha           \n"
        "\n"
        "      ---Alternativos---       \n"
        "       C: cerrar el juego      \n");

    Sleep(5000);
    system("cls");
}

char decode_char(char char_to_decode)
{
    return char_to_decode ^ 0x55; // Operación XOR por acá con el número 85.
}

// TODO WIP.
void animation_of_decode(char string[])
{
    // Decodificar primero...
    for (size_t i = 0; string[i] != '\0'; i++)
    {
        string[i] = decode_char(string[i]);
    }
    // Luego imprimir en pantalla:
    for (size_t i = 0; string[i] == '\0'; i++)
    {
        string[i] = decode_char(string[i]);
        printf("%c", string[i]);
        Sleep(1000);
        system("cls");
    }
}