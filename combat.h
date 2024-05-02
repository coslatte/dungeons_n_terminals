#pragma once

/**
 * Estructura definida para generar y plantear un combate.
 */
typedef struct Combat
{
    int hero_health;
    int enemy_health;
} Combat;

/**
 * Crea un `Combat` definiendo la vida del enemigo y la del héroe.
 *
 * @param enemy_health Vida del enemigo.
 * @param hero_health Vida del héroe.
 */
Combat create_combat(int enemy_health, int hero_health);

/**
 * Inicia un combate. Crea un campo `Combat` que se almacena en memoria.
 */
void start_combat();

/**
 * Muestra en el terminal de comandos las opciones que tiene el jugador
 * disponible para usar tales como: Atacar, Retirarse, etc..
 */
void show_options();

/**
 * Muestra una representación ASCII del combate.
 */
void show_image();

/**
 * Hace que el héroe disminuya la vida del enemigo en un número.
 * Si el daño es superior a la vida actual del enemigo, éste muere.
 *
 * @param damage Daño provocado al enemigo por parte del héroe.
 */
void hero_attacks_enemy(int damage);

/**
 * Hace que el enemigo le haga daño al héroe. Si el daño provocado es mayor
 * a la cantidad actual de vida que tiene el héroe, éste muere.
 *
 * @param damage Daño provocado al héroe por parte del enemigo.
 */
void enemy_attacks_hero(int damage);

/**
 * Pone fin al combate.
 */
void end_combat();