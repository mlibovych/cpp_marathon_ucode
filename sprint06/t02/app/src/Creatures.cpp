#include <Creatures/Creature.h>
#include <Creatures/Imperial.h>
#include <Creatures/Redguard.h>

namespace Creatures {
    std::string getSpellName(const Spells::SpellType spell) {
        std::map<Spells::SpellType, std::string> spellNames {
            {Spells::SpellType::Equilibrium, "equilibrium"},
            {Spells::SpellType::Fireball, "fireball"},
            {Spells::SpellType::Flames, "flames"},
            {Spells::SpellType::Freeze, "freeze"},
            {Spells::SpellType::Healing, "healing"},
        };

        return spellNames[spell];
    }

    Creature::Creature(const std::string& name) : m_name(name), m_health(100), m_mana(100) {
        std::cout << m_name << " was born!" << std::endl;
    }

    Creature::~Creature() {
        for (auto it : m_spells) {
            delete it;
        }
    }

    std::string Creature::getName() const {
        return m_name;
    };

    int Creature::getHealth() const {
        return m_health;
    };

    int Creature::getMana() const {
        return m_mana;
    };

    void updateData(int& data) {
        if (data < 0) {
            data = 0;
        }
        if (data > 100) {
            data = 100;
        }
    }

    void Creature::setHealth(int health) {
        updateData(health);
        m_health = health;
    }

    void Creature::setMana(int mana) {
        updateData(mana);
        m_mana = mana;
    };

    void Creature::learnSpell(Spells::ISpell* spell) {
        if (!m_spells.count(spell)) {
            m_spells.insert(spell);
            std::cout << m_name << " has learned the " << getSpellName(spell->getType()) << " spell successfully!" << std::endl;
        }
        else {
            std::cout << m_name << " already knows the " << getSpellName(spell->getType()) << " spell!" << std::endl;
        }
    }

    void Creature::castSpell(const Spells::SpellType type, Creature& creature) {
        auto spell_it = std::find_if(m_spells.begin(), m_spells.end(), [type](Spells::ISpell* spell){
            return spell->getType() == type;
        });
        Spells::ISpell* spell_c = *spell_it;
        if (spell_it == m_spells.end()) {
            std::cout << m_name << " doesn't know the " << getSpellName(type) << " spell." << std::endl;
            return;
        }
        if (!spell_c->cast(*this, creature)) {
            std::cout << m_name << " can't cast the " << getSpellName(type) << "!" << std::endl;
        }
        else {
            std::cout << m_name << " has cast the " << getSpellName(type) << " spell on " << creature.getName() << "!" << std::endl;
        }
    }

    Imperial::Imperial(const std::string name) : Creature(name) {};

    void Imperial::sayPhrase() const {
        std::cout << "I am " << getName() << ", Imperial soldier! Stop right here!" << std::endl;
    };

    Redguard::Redguard(const std::string name) : Creature(name) {};

    void Redguard::sayPhrase() const {
        std::cout << "I am " << getName() << " from Redguards, wanna trade?" << std::endl;
    };
}

std::ostream& operator<<(std::ostream& os, const Creatures::Creature& creature) {
    os << creature.getName() << " : " << creature.getHealth() << " HP, " << creature.getMana() << " MP.";
    return os;
}