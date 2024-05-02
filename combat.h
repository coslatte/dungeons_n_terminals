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
int start_combat();

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
 * Muestra la salud del héroe en consola.
 */
void show_hero_health();

/**
 * Muestra la salud del enemigo en consola.
 */
void show_enemy_health();

/**
 * Se encarga de traducir la opción que ingresa el usuario en el menú
 * de combate a una operación de las definidas.
 *
 * @param decision Un numero que representa la decisión a tomar, si atacar, escapar, etc..
 * `Q` = Atacar. `R` = Escapar.
 * @returns `1` si el usuario decide atacar, `2` si decide escapar.
 */
int take_decision(char decision);

/**
 * Hace que el héroe disminuya la vida del enemigo en `damage` número.
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
 * Se encarga de renderizar las imagenes del combate.
 */
void render_screen();

/**
 * Función para expresar que el Héroe ha escapado de la batalla.
 */
void hero_runs();
/**
 * Pone fin al combate.
 */
void end_combat();