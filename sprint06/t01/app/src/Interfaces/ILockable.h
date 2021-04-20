#pragma once

#include <Containers/LockpickDifficulty.h>
#include <iostream>

class ILockable {
public:
    virtual LockpickDifficulty lockDifficulty() const = 0;
    virtual bool isLocked() const = 0;
};