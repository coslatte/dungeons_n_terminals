#include "combat.h"
#include "functions.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

Combat combat;
bool fighting;
bool can_run = true;
bool bro_really_said_run = false;
int funny_counter = 0;
int static_hero_health = 100;

Combat create_combat(int enemy_health)
{
    fighting = true;
    Combat combat = {.hero_health = static_hero_health, .enemy_health = enemy_health};
    return combat;
}

int start_combat()
{
    combat = create_combat(50);

    do
    {
        render_combat_screen();
        show_choise_msg();             // Simplemente para mostrar en pantalla que debe tomar una decisión.
        take_decision(read_console()); // Paso sumamente importante acá!
        if (!fighting)                 // Si se acabó el combate y se devuelve 1.
            return 1;
        if (bro_really_said_run) // Caso si el heroe huye. Se devuelve 2.
            return 2;
    } while (fighting || !bro_really_said_run); // Combate dudará hasta que se rompa el ciclo.
}

void take_decision(char decision)
{
    srand(time(NULL));                      // Inicialización de una semilla con la hora actual.
    int random_dmg_hero = 5 + rand() % 41;  // Daño en el rango de `5 < dmg < 45`.
    int random_dmg_enemy = 5 + rand() % 41; // Daño en el rango de `5 < dmg < 45`.
    if (decision == 'q' || decision == 'r')
        decision -= 32;
    switch (decision)
    {
    case 'Q':
        hero_attacks_enemy(random_dmg_hero); // El héroe ataca al enemigo.
        if (!fighting)
            return;
        enemy_attacks_hero(random_dmg_enemy); // Enemigo ataca al héroe.
        break;
    case 'R':
        if (can_run == false)
        {
            switch (funny_counter)
            {
            case 0:
                printf("Na en serio creias que podias huir? xd.\n");
                funny_counter++;
                Sleep(2500);
                break;
            case 1:
                printf("No puedes huir.\n");
                funny_counter++;
                Sleep(2500);
                break;
            case 2:
                printf("XD\n");
                Sleep(2500);
                funny_counter++;
                break;
            case 3:
                printf("No puedes huir.\n");
                Sleep(2500);
                break;
            default:
                break;
            }
            enemy_attacks_hero(random_dmg_enemy); // Enemigo ataca al héroe.
        }
        else
            hero_try_run();
        break;
    case '*':
        printf("papa que haces...\n");
        break;
    default:
        break;
    }
}

void hero_attacks_enemy(int damage)
{
    if (damage > combat.enemy_health)
    {
        combat.enemy_health = 0;
        printf("Combate finalizado: Heroe mato a enemigo.\n");
        fighting = false;
        Sleep(2500);
        return;
    }
    else
    {
        printf("HEROE ataca -> ENEMIGO. %d puntos de damage.\n", damage);
        combat.enemy_health -= damage;
        Sleep(2500);
    }
}

void enemy_attacks_hero(int damage)
{
    if (damage > static_hero_health)
    {
        static_hero_health = 0;
        system("cls");
        printf("Combate finalizado: Enemigo mato al heroe.\n");
        system("cls");
        printf("Fin del Juego.\n");
        Sleep(5000);
        exit(0);
    }
    else
    {
        printf("ENEMIGO ataca -> HEROE. %d puntos de damage.\n", damage);
        static_hero_health -= damage;
        Sleep(2500);
    }
}

void hero_try_run()
{
    srand(time(NULL));         // Inicialización de una semilla con la hora actual.
    int chance = rand() % 101; // Probabilidad de huir en el rango de `0 < chance < 100`.
    if ((rand() % 101) > chance)
    {
        printf("El heroe ha logrado escapar del combate.\n");
        bro_really_said_run = true;
        Sleep(2500);
    }
    else
    {
        printf("Cagaste... no se pudo escapar... O_o\n");
        can_run = false;
        Sleep(2500);
    }
}

void render_combat_screen()
{
    system("cls");
    show_image();
    show_options();
    show_hero_health();
    show_enemy_health();
}

void show_image()
{
    printf(
        "<-------------------------------------------------------------------->\n"
        "|                                              ____                  |\n"
        "|                                       __,---'     `--.__           |\n"
        "|                       .            ,-'                ; `.         |\n"
        "|                                   ,'                  `--.`--.     |\n"
        "|    .                     .       ,'                       `._ `-.  |\n"
        "|                                  ;                     ;     `-- ; |\n"
        "|             .      ..          ,-'-_       _,-~~-.      ,--      `.|\n"
        "|                                ;;   `-,;    ,'~`.__    ,;;;    ;  ;|\n"
        "|                                ;;    ;,'  ,;;      `,  ;;;     `. ;|\n"
        "|                                `:   ,'    `:;     __/  `.;      ; ;|\n"
        "|                                 ;~~^.   `.   `---'~~    ;;      ; ;|\n"
        "|                   .             `,' `.   `.            .;;;     ;' |\n"
        "|       .                         ,',^. `.  `._    __    `:;     ,'  |\n"
        "|                                 `-' `--'    ~`--'~~`--.  ~    ,'   |\n"
        "|                                /;`-;_ ; ;. /. /   ; ~~`-.     ;    |\n"
        "|     .         .               ; ;  ; `,;`-;__;---;      `----'     |\n"
        "|                               ``-`-;__;:  ;  ;__;                  |\n"
        "|                      .              `-- `-'                        |\n"
        "|                                                                    |\n"
        "|    . .  ;;X@@      .       .    .. .                     ..        |\n"
        "|  .  .S.X 8x:8SS..    . .    .  .. .                                |\n"
        "|   . .X x X88t; xx. .     .      .    .      .         .            |\n"
        "|  . .@S:8 S .;8X 8 .   .   .  .  .. .                               |\n"
        "|    ...;@X@:tx.8:    .   .     .    .    .     .                    |\n"
        "|  . .:8; ;XX X:: .     .    .     .   .     .                       |\n"
        "| . X@X@88.@@ xS:.. . .    .   . .   .   . .   .  .        ..        |\n"
        "| . :8  @ S 88;8t; .S .  .   .     .   .                             |\n"
        "|. SX  ;88  ; 8SS @8x;.         .         .  . . .                   |\n"
        "| .x.;   @t@@:S.;.:Sxt .  . . .   .  .  .   .         ..             |\n"
        "|  ..@.. ..tt:8. 8:.    .           .     .    .                     |\n"
        "<-------------------------------------------------------------------->\n");
}

void show_options()
{
    if (can_run)
        printf(
            "--- Opciones disponibles ---\n"
            "Atacar:      Q              \n"
            "Retirarse:   R              \n");
    else
        printf(
            "--- Opciones disponibles ---\n"
            "Atacar:      Q              \n"
            "xxxxxxxxx:   *              \n");
}

void show_enemy_health() { printf("Vida del ENEMIGO: %d\n", combat.enemy_health); }

void show_hero_health() { printf("Vida del HEROE:   %d\n", static_hero_health); }

void show_choise_msg() { printf(">>> Tome una decision: "); }