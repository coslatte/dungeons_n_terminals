#pragma once

/**
 * Comienza una animación que anuncia que se está inicia el combate.
 */
void animation_starting_combat();

/**
 * Muesta por pantalla al jugador una introducción al juego, posiblemente una especie de lore
 * y otras cositas que se pueden ir agregando quizás.
 */
void game_text_intro();

/**
 * Util para la animación de decodificar caracteres y eso.
 * @param char_to_decode Es el caracter que se va a decodificar-codificar.
 * @return El caracter decodificado.
 */
char decode_char(char char_to_decode);

/**
 * Esto comienza una animación donde cada caracter de la cadena de caracteres
 * aparece codificado, y se va decodificando poco a poco hasta mostrar todo el mensaje.
 */
void animation_of_decode(char string[]);