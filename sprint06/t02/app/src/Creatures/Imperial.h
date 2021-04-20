#pragma once

#include <string>
#include "Creature.h"

namespace Creatures {
class Imperial : public Creature  {
public:
    Imperial(const std::string name);
    void sayPhrase() const override;
};
}