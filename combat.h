#pragma once

typedef struct Combat
{
    int hero_health;
    int enemy_health;
} Combat;

int init_combat_properties(int enemy_health, int hero_health);

int start_combat();

int hero_attacks_enemy();

int enemy_attacks_hero();

int end_combat();