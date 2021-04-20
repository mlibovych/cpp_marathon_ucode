#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>

class Calc {
    std::map<std::string, int> variables;
public:
    int Operation (int operand1, int operand2,
                    std::string& operation) {
        if (operation == "+") {
            return operand1 + operand2;
        }
        else if (operation == "-") {
            return operand1 - operand2;
        }
        else if (operation == "*") {
            return operand1 * operand2;
        }
        else {
            if (!operand2) {
                throw std::runtime_error("division by zero");
            }
            return operand1 / operand2;
        }
    }

    void UpdateVariable (std::string& variable,
                         int operand1, int operand2,
                         std::string& operation) {
        variables[variable] = Operation(operand1, operand2, operation);
    }

    int Search(const std::string& variable, int num) const {
        if (!variables.count(variable)) {
            throw std::runtime_error("invalid operand" + std::to_string(num));
        }
        return variables.at(variable);
    }
};

void CheckCommand (std::string& line, Calc& calc);