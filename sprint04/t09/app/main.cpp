#include "Dragonborn.h"

int main(int argc, char** argv) {
    try {
        std::map<std::string, Dragonborn::Actions> actions {
            {"shout", Dragonborn::Actions::Shout},
            {"magic", Dragonborn::Actions::Magic},
            {"weapon", Dragonborn::Actions::Weapon},
        };
        Dragonborn::Actions action;
        Dragonborn dovakin;

        if (argc != 2) {
            throw std::runtime_error("usage: ./dragonborn [action]");
        }
        action = actions.at({argv[1]});
        dovakin.executeAction(action);
    }
    catch (std::runtime_error& re) {
        std::cerr << re.what() << std::endl;
    }
    catch (std::out_of_range& ofr) {
        std::cerr << "Invalid action" << std::endl;
    }
}