#include <time.h>
#include <stdlib.h>
#include "Enemy.h"

Enemy::Enemy(const char* name, float health, float damage, float defense)
{
    m_name = name;
    m_health = health;
    m_damage = damage;
    m_defense = defense;
}

float Enemy::attack(Character* other)
{
    /* initialize random seed: */
    srand(time(NULL));
    /* generate secret number between 1 and 10: */
    float randomDamage = rand() % 10 + 1;

    return getDamage() + randomDamage;
}
