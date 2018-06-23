#include <BinomialCalculator.h>
#include <LineParser.h>
#include <iostream>
#include "BadInputExc.h"

using test_task_main::LineParser;
using test_task_main::BinomialCalculator;
using test_task_main::BadInputExc;

int main() {
    LineParser parser;
    BinomialCalculator calc;
    std::cout << "Enter n and k (for example 5 3), or exit" << std::endl;
    while(true){
        // Считываем строку
        std::string line;
        std::getline(std::cin, line);
        LineParser::NKOrExit nkOrExit;
        try {
            // Обрабатываем ввод
            nkOrExit = parser.parseLine(line);
        } catch (const BadInputExc &exc){
            std::cerr << "Error: " << exc.what() << std::endl;
            continue;
        }
        // Выход
        if(nkOrExit.exit){
            return 0;
        }
        // Рассчитываем результат
        std::cout << "Result: " << calc.calc(nkOrExit.n, nkOrExit.k) << std::endl;

    }
}