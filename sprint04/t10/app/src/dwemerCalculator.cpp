#include "dwemerCalculator.h"

// std::regex re("[\\+\\-]{0,1}[0-9|A-z]+");
// std::sregex_iterator next(line.begin(), line.end(), re);
// std::sregex_iterator end;
// while (next != end) {
//     std::smatch match = *next;
//     std::cout << match.str() << "\n";
//     next++;
// }

// void CheckVariable(const std::string& str, int num) {

// }


void CheckOperand(std::string& str, int num, int& operand, Calc& calc) {
    if (std::regex_search (str, std::regex("[\\+\\-]{0,1}[0-9]+")) && std::regex_search (str, std::regex("[A-z]+"))) {
        throw std::invalid_argument("invalid operand" + std::to_string(num));
    }
    if (std::regex_search (str, std::regex("[\\+\\-]{0,1}[0-9]+"))) {
        try {
            operand = std::stoi(str);
        }
        catch (std::out_of_range& oor) {
            throw std::out_of_range ("operand" + std::to_string(num) + " is out of range");
        }
    }
    else {
        bool flag = 0;
        if (std::regex_search (str, std::regex("[\\+\\-]"))) {
            if (std::regex_search (str, std::regex("[-]"))) {
                flag = 1;
            }
            str = str.substr(1);
        }
        operand = calc.Search(str, num);
        if (flag) {
            operand *= -1;
        }
    }
}

void Find (std::string line, Calc& calc) {
    std::smatch match;
    std::string operation, variable, tmp;
    int operand1, operand2;

    std::regex_search(line, match, std::regex("[\\+\\-]{0,1}[0-9|A-z]+"));
    tmp = match.str();
    CheckOperand(tmp, 1, operand1, calc);
    line = match.suffix().str();

    std::regex_search(line, match, std::regex("[[\\+\\-\\*\\/]"));
    operation = match.str();
    line = match.suffix().str();

    std::regex_search(line, match, std::regex("[\\+\\-]{0,1}[0-9|A-z]+"));
    tmp = match.str();
    CheckOperand(tmp, 2, operand2, calc);
    line = match.suffix().str();

    if (std::regex_search(line, match, std::regex("="))) {
        line = match.suffix().str();
        std::regex_search(line, match, std::regex("[A-z]+"));
        variable = match.str();
        calc.UpdateVariable(variable, operand1, operand2, operation);
    }
    std::cout << calc.Operation(operand1, operand2, operation) << std::endl;
}

void CheckCommand (std::string& line, Calc& calc) {
    if (!std::regex_match (line,
        std::regex("[\\s]*[\\+\\-]{0,1}(([0-9]+)|([A-z]+))[\\s]*[\\+\\-\\*\\/][\\s]*[\\+\\-]{0,1}(([0-9]+)|([A-z]+))[\\s]*"))
        && !std::regex_match (line,
        std::regex("[\\s]*[\\+\\-]{0,1}(([0-9]+)|([A-z]+))[\\s]*[\\+\\-\\*\\/][\\s]*[\\+\\-]{0,1}(([0-9]+)|([A-z]+))[\\s]*=[\\s]*[A-z]+[\\s]*"))) {
        throw std::invalid_argument("invalid input");
    }
    Find(line, calc);
}