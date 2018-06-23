#pragma once

#include <string>

namespace test_task_main {
    class LineParser {
    private:
        /*
         * Преобразовать строку в число или выбросить исключение
         */
        uint_fast32_t parseNumber(const std::string &str, const std::string &name);
    public:
        struct NKOrExit{
            uint_fast32_t n;
            uint_fast32_t k;
            bool exit;
        };
        LineParser();
        /*
         * Найти два числа, сообщение о выходе или выбросить исключение при ошибке
         */
        NKOrExit parseLine(const std::string &line);
    };
}
