#include "meadSong.h"

std::string what(int count, int bottles, bool Upper) {
    if (count < 0) {
        count = bottles;
    }
    std::string vessle = "bottle";
    std::string first = Upper ? "N" : "n";
    std::string amount = count ? std::to_string(count) : first + "o more";
    if (count > 1 || !count) {
        vessle.push_back('s');
    }

    return amount + " " + vessle + " of mead";
}

std::string where() {
    return "on the wall";
}

void firstLine(int count, int bottles) {
    std::cout << what(count, bottles, 1) <<  " " << where() << ", "  << what(count, bottles, 0) << ". \n";
}

std::string countBottles(int count, int bottles) {
    std::string res = what(count, bottles, 0);
    
    res += " " + where() + ".";
    if (count >= 0) {
        res += "\n";
    }
    return res;
}

std::string doAction(int count) {
    std::string res;

    if (count >= 0) {
        std::string bottle = count ? "one" : "it";
        res = "Take " + bottle + " down and pass it around, ";
    }
    else {
        res = "Go to the store and buy some more, ";
    }
    return res;
}

void secondLine(int count, int bottles) {
    std::cout << doAction(count) << countBottles(count, bottles) << std::endl;
}

void continueSong(int* count, int bottles) {
    firstLine(*count, bottles);
    secondLine(--*count, bottles);
}

void singSong(int bottles) {
    int count = bottles;

    while (count >= 0) {
        continueSong(&count, bottles);
    }
}
