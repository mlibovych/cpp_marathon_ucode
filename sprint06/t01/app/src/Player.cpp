#include <Player/Player.h>
#include <Containers/Container.h>

Player::Player(const std::string& name) : m_name(name) {};

void Player::openContainer(Container* container) {
    std::cout << m_name << " ";
    if (container->tryToOpen(m_lockpickSkill)) {
        std::cout << "successfully opened ";
    }
    else {
        std::cout << "skill is too low to open ";
    }
    std::cout << container->name() << std::endl;
}

void Player::setLockpickSkill(LockpickDifficulty skill) {
    m_lockpickSkill = skill;
}