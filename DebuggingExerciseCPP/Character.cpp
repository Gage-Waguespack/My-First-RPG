#include "Character.h"

Character::Character()
{
	m_name = "Character";
	m_health = 100;
	m_damage = 10;
	m_defense = 5;
}

Character::Character(const char* name, float health, float damage, float defense)
{
	m_name = name;
	m_health = health;
	m_damage = damage;
	m_defense = defense;
}

float Character::takeDamage(float damage)
{
	float totalDamage = damage - m_defense;
	
	if (totalDamage < 0)
		totalDamage = 0;

	m_health -= totalDamage;
	return damage;
}

float Character::attack(Character* other)
{
	return other->takeDamage(getDamage());
}