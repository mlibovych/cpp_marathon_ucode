#include "libInventoryManager.h"

void CheckType (std::stringstream& ss, std::string& type) {
    ss >> type;
    if (type.empty()) {
        throw std::runtime_error("Invalid command.");
    }
}

void CheckEnd (std::stringstream& ss) {
    if (!ss.eof()) {
        throw std::runtime_error("Invalid command.");
    }
}

void CheckItemType (const std::string& type) {
    std::vector<std::string> types = {"w","f","a","p"};

    if (std::find(types.begin(), types.end(), type) == types.end()) {
        throw std::runtime_error("Invalid item.");
    }
}

void CheckItemOccurrence (const std::string& type, std::vector<std::string>& inventory) {
    auto it = std::find(inventory.begin(), inventory.end(), type);

    if (it == inventory.end()) {
        throw std::runtime_error("Invalid item.");
    }
    inventory.erase(it);
}

void CheckSize (std::vector<std::string>& inventory) {
    if (inventory.size() == 12) {
        throw std::runtime_error("Inventory is full.");
    }
}

void Insert(const std::string& type, std::vector<std::string>& inventory) {
    CheckItemType(type);
    CheckSize(inventory);
    inventory.push_back(type);
    std::cout << type << " was inserted." << std::endl;
}

void Remove(const std::string& type, std::vector<std::string>& inventory) {
    CheckItemType(type);
    CheckItemOccurrence(type, inventory);
    std::cout << type << " was removed." << std::endl;
}

void Show(const std::vector<std::string>& inventory) {
    std::cout << "Inventory { ";
    for (const auto& it : inventory) {
        std::cout << it << " ";
    }
    for (int i = inventory.size(); i < 12; i++) {
        std::cout << "-" << " ";
    }
    std::cout << "}" << std::endl;
}

void Help(void) {
    std::cout << "Available commands:" << std::endl
    << "1. insert <itemType>" << std::endl
    << "2. remove <itemType>" << std::endl
    << "3. show" << std::endl
    << "4. help" << std::endl
    << "5. exit" << std::endl;
}

void CheckCommand (bool& process, std::stringstream& ss,
                   std::vector<std::string>& inventory) {
    std::string command, type;

    ss >> command;
    if (command == "exit") {
        CheckEnd(ss);
        std::cout << "Bye." << std::endl;
        process = 0;
    }
    else if (command == "insert") {
        CheckType(ss, type);
        CheckEnd(ss);
        Insert(type, inventory);
    }
    else if (command == "remove") {
        CheckType(ss, type);
        CheckEnd(ss);
        Remove(type, inventory);
    }
    else if (command == "show") {
        CheckEnd(ss);
        Show(inventory);
    }
    else if (command == "help") {
        CheckEnd(ss);
        Help();
    }
    else {
        std::cerr << "Invalid command." << std::endl;
    }
}