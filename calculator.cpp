// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include "calculator.h"
#include <iostream>
#include <cmath>

bool ReadNumber(Number& result) {
    if(!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number number;
    Number arg;
    Number memory;

    bool memory_empty = true;

    std::string command;

    if (!ReadNumber(number)) {
    return false;
        }

    while (std::cin >> command) {
        if (command == "q") {
            break;
        }
        else if (command == "=") {
            std::cout << number << std::endl;
        }
        else if (command == "c") {
            number = 0;
        }
        else if (command == ":") {
            if (!ReadNumber(number)) {  
                return false;        
            }
        }
        else if (command == "s") {
            memory = number;
            memory_empty = false;
        }
        else if (command == "l") {
            if (!memory_empty) {
            number = memory;
            }
            else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        }
        else if (command == "+" || command == "-" ||
                 command == "*" || command == "/" || command == "**") {
            
            if (!ReadNumber(arg)) {  
                return false;        
            }

            if (command == "+") {
                number = number + arg;
            }
            else if (command == "-") {
                number = number - arg;
            }
            else if (command == "*") {
                number = number * arg;
            }
            else if (command == "/") {
                number = number / arg;
            }
            else if (command == "**") {
                number = std::pow(number, arg);
            }
        }
        else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }
    }
    return true;
}