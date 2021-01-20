#include <time.h>
#include <stdlib.h>
#include "Player.h"


Player::Player(const char* name, float health, float damage, float defense)
{
    m_name = name;
    m_health = health;
    m_damage = damage;
    m_defense = defense;
}

float Player::equipWeapon(Item item)
{
    return Player::getDamage() + item.getStatusBoost();
}

float Player::takeDamage(float damage)
{
    float totalDamage = damage - m_defense;

    if (totalDamage < 0)
        totalDamage = 0;

    m_health -= totalDamage;
    return damage;
}

float Player::attack(Character* other)
{
    /* initialize random seed: */
    srand(time(NULL));

    /* generate secret number between 1 and 10: */
    float randomDamage = rand() % 25 + -10;

    return other->takeDamage(getDamage() + randomDamage);
}

float Player::getDamage()
{
    return Character::getDamage() + m_weapon.getStatusBoost();
}

float Player::getDefense()
{
    return Character::getDefense() + m_shield.getStatusBoost();
}
