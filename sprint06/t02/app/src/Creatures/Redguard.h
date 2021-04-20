#pragma once

#include <string>
#include "Creature.h"

namespace Creatures {
class Redguard : public Creature  {
public:
    Redguard(const std::string name);
    void sayPhrase() const override;
};
}