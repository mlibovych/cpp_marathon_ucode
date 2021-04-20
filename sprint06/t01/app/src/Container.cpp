#include <Containers/Container.h>
#include <Containers/Barrel.h>
#include <Containers/Chest.h>
#include <Containers/Safe.h>
#include <Containers/LockpickDifficulty.h>

Container::Container(bool isLocked, const LockpickDifficulty difficulty) : m_isLocked(isLocked),
                                                                           m_difficulty(difficulty) {}

LockpickDifficulty Container::lockDifficulty() const {
    return m_difficulty;
}
bool Container::isLocked() const {
    return m_isLocked;
}

bool Container::tryToOpen(LockpickDifficulty skill) {
    if(!m_isLocked) {
        return 1;
    }
    if (skill >= m_difficulty) {
        m_isLocked = false;
        return true;
    }
    return false;
}

Barrel::Barrel() : Container(false, LockpickDifficulty::None) {}

std::string Barrel::name() const {
    return "Barrel";
}

Chest::Chest(bool isLocked, const LockpickDifficulty difficulty) : Container(isLocked, difficulty) {}

std::string Chest::name() const {
    return "Chest";
}

Safe::Safe(bool isLocked, const LockpickDifficulty difficulty) : Container(isLocked, difficulty) {}

std::string Safe::name() const {
    return "Safe";
}