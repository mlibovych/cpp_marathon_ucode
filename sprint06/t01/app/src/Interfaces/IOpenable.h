#pragma once

#include <Containers/LockpickDifficulty.h>

class IOpenable {
public:
    virtual bool tryToOpen (LockpickDifficulty diff) = 0;
};