#include "Spells/ISpell.h"
#include "Spells/EquilibriumSpell.h"
#include "Spells/FireballSpell.h"
#include "Spells/FlamesSpell.h"
#include "Spells/FreezeSpell.h"
#include "Spells/HealingSpell.h"
#include "Creatures/Creature.h"

namespace Spells {
    bool EquilibriumSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
        if (spellcaster.getHealth() < 25) {
            return false;
        }
        spellcaster.setHealth(spellcaster.getHealth() - 25);
        target.setMana(target.getMana() + 25);
        return true;
    }

    SpellType EquilibriumSpell::getType() const {
        return SpellType::Equilibrium;
    }

    bool FireballSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
        if (spellcaster.getMana() < 50) {
            return false;
        }
        spellcaster.setMana(spellcaster.getMana() - 50);
        target.setHealth(target.getHealth() - 40);
        return true;
    }

    SpellType FireballSpell::getType() const {
        return SpellType::Fireball;
    }

    bool FlamesSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
        if (spellcaster.getMana() < 14) {
            return false;
        }
        spellcaster.setMana(spellcaster.getMana() - 14);
        target.setHealth(target.getHealth() - 8);
        return true;
    }

    SpellType FlamesSpell::getType() const {
        return SpellType::Flames;
    }

    bool FreezeSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
        if (spellcaster.getMana() < 30) {
            return false;
        }
        spellcaster.setMana(spellcaster.getMana() - 30);
        target.setHealth(target.getHealth() - 20);
        return true;
    }

    SpellType FreezeSpell::getType() const {
        return SpellType::Freeze;
    }

    bool HealingSpell::cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
        if (spellcaster.getMana() < 15) {
            return false;
        }
        spellcaster.setMana(spellcaster.getMana() - 15);
        target.setHealth(target.getHealth() + 10);
        return true;
    }

    SpellType HealingSpell::getType() const {
        return SpellType::Healing;
    }
}

bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs) {
    return lhs.getType() == rhs.getType();
}