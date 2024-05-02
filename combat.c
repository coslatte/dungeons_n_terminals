#include "combat.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

Combat combat;
bool fighting;

Combat create_combat(int hero_health, int enemy_health)
{
    Combat combat = {.hero_health = hero_health, .enemy_health = enemy_health};
    fighting = true;
    return combat;
}

int start_combat()
{
    combat = create_combat(50, 50);

    fighting = true;

    while (fighting)
    {
        render_screen();
        char input = getchar(); // 'Q': Atacar, 'R': Escapar
        if (input == 'q' || input == 'r')
            input -= 32;
        else
            continue;
        take_decision(input);
    }
    Sleep(100);
    return 1;
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
    printf(
        "--- Opciones disponibles ---\n"
        "Atacar:      Q              \n"
        "Retirarse:   R              \n");
}

void show_enemy_health()
{
    printf("Vida del enemigo: %d\n", combat.enemy_health);
}

void show_hero_health()
{
    printf("Vida del heroe: %d\n", combat.hero_health);
}

void hero_runs()
{
    printf("El heroe ha escapado del combate.\n");
    Sleep(1000);
    end_combat();
}

int take_decision(char decision)
{
    srand(time(NULL));                      // Inicialización de una semilla con la hora actual.
    int random_dmg_hero = 5 + rand() % 41;  // Daño en el rango de `5 < dmg < 45`.
    int random_dmg_enemy = 5 + rand() % 41; // Daño en el rango de `5 < dmg < 45`.
    switch (decision)
    {
    case 'Q':
        hero_attacks_enemy(random_dmg_hero);
        if (combat.enemy_health > 0)
            enemy_attacks_hero(random_dmg_enemy);
        Sleep(500);
        return 1;
    case 'R':
        hero_runs();
        return 2;
    default:
        exit(EXIT_FAILURE);
    }
}

void hero_attacks_enemy(int damage)
{
    if (damage > combat.enemy_health)
    {
        printf("Combate finalizado: Heroe mato a enemigo.\n");
        Sleep(1500);
        combat.enemy_health = 0;
        end_combat();
    }
    else
    {
        printf("Heroe ataco a enemigo realizando %d puntos de damage.\n", damage);
        Sleep(1500);
        combat.enemy_health -= damage;
    }
}

void enemy_attacks_hero(int damage)
{
    if (damage > combat.hero_health)
    {
        printf("Combate finalizado: Enemigo mato al heroe.");
        combat.hero_health = 0;
        printf("f");
        Sleep(1000);
        system("cls");
        printf("perdiste");
        Sleep(1000);
        system("cls");
        printf("que fula...");
        Sleep(350);
        system("cls");
        Sleep(300);
        printf("GAME OVER");
        Sleep(3000);
        system("cls");
        end_combat();
    }
    else
    {
        printf("Enemigo ataco a heroe realizando %d puntos de damage.\n", damage);
        combat.hero_health -= damage;
    }
}

void render_screen()
{
    system("cls");
    show_image();
    show_options();
    show_hero_health();
    show_enemy_health();
}

void end_combat()
{
    fighting = false;
}