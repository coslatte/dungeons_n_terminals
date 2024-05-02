#include "combat.h"

#include <stdio.h>

Combat combat;

Combat create_combat(int hero_health, int enemy_health)
{
    Combat combat = {.hero_health = hero_health, .enemy_health = enemy_health};
    return combat;
}

void start_combat()
{
    combat = create_combat(50, 50);
    show_image();
    show_options();
}

void show_image()
{
    printf(
        "                                  . .Xt:          \n"
        "  .  . .  .  . .  .  . .  .  . . .;. x 8xX. .  .  \n"
        "   .       .       .       .     .:8 . 8X S: .   .\n"
        "     .  .    .  .    .  .    .  .  X:x;:8.S .  .  \n"
        " .       .       .       .       . .XS 8x@;8 .    \n"
        "   .  .    .  .    .  .    .  .   . x.x;88S8.   . \n"
        "  .    .. . .  .  .    .  .    .   ;8 S8S .   .   \n"
        "    . .  ;;X@@      .       .    ....:tt . .    . \n"
        "  .  .S.X 8x:8SS..    . .    .  . . ::.; 8 . .    \n"
        "   . .X x X88t; xx. .     .      . 8S@;8 ;.    .  \n"
        "  . .@S:8 S .;8X 8 .   .   .  .  . 8S;. X8.. .   .\n"
        "    ...;@X@:tx.8:    .   .     .    .    .     .  \n"
        "  . .:8; ;XX X:: .     .    .     .   .     .     \n"
        " . X@X@88.@@ xS:.. . .    .   . .   .   . .   .  .\n"
        " . :8  @ S 88;8t; .S .  .   .     .   .           \n"
        ". SX  ;88  ; 8SS @8x;.         .         .  . . . \n"
        " .x.;   @t@@:S.;.:Sxt .  . . .   .  .  .   .      \n"
        "  ..@.. ..tt:8. 8:.    .           .     .    .   \n");
}

void show_options()
{
    printf("Opciones disponibles:\nAtacar: Q\nRetirarse: R\n");
}

void hero_attacks_enemy(int damage)
{
    if (damage > combat.enemy_health)
    {
        printf("Combate finalizado: Heroe mato a enemigo.");
        end_combat();
    }
    else
    {
        combat.enemy_health - damage;
    }
}

void enemy_attacks_hero(int damage)
{
    if (damage > combat.hero_health)
    {
        printf("Combate finalizado: Enemigo mato a heroe.");
        end_combat();
    }
    else
    {
        combat.hero_health - damage;
    }
}

void end_combat()
{
    // TODO: finalizar el combate
}