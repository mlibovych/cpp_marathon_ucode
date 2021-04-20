#pragma once

class Weapon {
    const int m_damage;
public:
    explicit Weapon(int damage);
    virtual ~Weapon() = default;
    int getDamage() const;
};