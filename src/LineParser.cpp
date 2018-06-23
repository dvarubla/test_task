#include "LineParser.h"
#include "BadInputExc.h"

using namespace test_task_main;

LineParser::NKOrExit LineParser::parseLine(const std::string &line) {
    NKOrExit res = {};
    if(line == "exit"){
        res.exit = true;
        return res;
    }
    // Разбиваем строку по пробелу
    auto index = line.find(' ');
    if(index == std::string::npos){
        throw BadInputExc("Space symbol not found");
    }
    auto partN = line.substr(0, index);
    auto partK = line.substr(index + 1);

    // Проверяем, совпадает ли с exit
    if(partN == "exit" || partK == "exit"){
        res.exit = true;
        return res;
    } else {
        res.exit = false;
    }
    // Переводим в числа
    res.n = parseNumber(partN, "N");
    res.k = parseNumber(partK, "K");
    return res;
}

uint_fast32_t LineParser::parseNumber(const std::string &str, const std::string &name) {
    size_t pos;
    uint_fast32_t res;
    try {
        res = std::stoul(str, &pos);
    } catch (const std::exception &ex){
        throw BadInputExc("Error reading number " + name);
    }
    // Если есть лишние символы
    if(pos != str.length()){
        throw BadInputExc("Extra symbols when reading " + name);
    }
    return res;
}

LineParser::LineParser() = default;
