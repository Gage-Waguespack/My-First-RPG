#pragma once
#include "Character.h"
#include "Item.h"

class Player : public Character
{
public:
    Player() : Character() {}
    Player(const char* name, float health, float damage, float defense);

    /// <summary>
    /// Adds the given item's stat boost to this player's total damage.
    /// </summary>
    /// <param name="item">The players new weapon.</param>
    float equipWeapon(Item item);

    /// <summary>
    /// Adds the given item's stat boost to this player's total defense.
    /// </summary>
    /// <param name="item">The player's new defense item</param>
    void equipShield(Item item) { m_shield = item;}

    // Inherited via Character

    /// <summary>
    /// Reduces the damage taken by the defense amount. 
    /// If the player has a shield equipped, the damage is reduced even more by
    /// the shield boost.
    /// </summary>
    /// <param name="damage">The damage to deal to the player.</param>
    /// <returns>The total damage the player took.</returns>
    virtual float takeDamage(float damage);

    /// <summary>
    /// Calls the takeDamage function for the given character and passes in the player's damage value.
    /// If the player has a weapon equipped, the damage is raised by the stat boost.
    /// </summary>
    /// <param name="other">The character to attack.</param>
    /// <returns>The total damage dealt.</returns>
    virtual float attack(Character* other);

    virtual const char* getName() { return m_name; }

    virtual float getHealth() { return m_health; }
    
    /// <returns>The player's base damage combined with the weapon stat boost.</returns>
    virtual float getDamage();
    
    /// <returns>The player's base defense combined with the shield stat boost.</returns>
    virtual float getDefense();

private:
    const char* m_name = new char();
    float m_health = 0;
    float m_damage = 0;
    float m_defense = 0;
    Item m_weapon;
    Item m_shield;
};

