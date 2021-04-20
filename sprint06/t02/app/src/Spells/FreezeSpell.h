#pragma once

#include "ISpell.h"

namespace Spells {
class FreezeSpell : public ISpell {
public:
    bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) override;
    SpellType getType() const override;
};
}