#include <gtest/gtest.h>
#include <LineParser.h>
#include <BadInputExc.h>

using test_task_main::LineParser;
using test_task_main::BadInputExc;

//Проверка работы класса-парсера
class LineParserT: public ::testing::Test {
public:
    LineParser parser;
    LineParserT() = default;
};

// Выход
TEST_F(LineParserT, Exit){
    EXPECT_TRUE(parser.parseLine("exit").exit);
}

// Выход c n
TEST_F(LineParserT, ExitN){
    EXPECT_TRUE(parser.parseLine("exit 222").exit);
}

// Выход с k
TEST_F(LineParserT, ExitK){
    EXPECT_TRUE(parser.parseLine("222 exit").exit);
}

// Переданы N и K
TEST_F(LineParserT, NK){
    auto res = parser.parseLine("222 333");
    EXPECT_FALSE(res.exit);
    EXPECT_EQ(res.n, 222);
    EXPECT_EQ(res.k, 333);
}

// Нет пробела
TEST_F(LineParserT, NoSpace){
    try {
        parser.parseLine("222333");
        FAIL();
    } catch (const BadInputExc &exc){
    }
}

// Слишком большое число
TEST_F(LineParserT, TooBigNumber){
    try {
        parser.parseLine("222 33399999999999999999999999999999");
        FAIL();
    } catch (const BadInputExc &exc){
    }
}

// Не число
TEST_F(LineParserT, NotANumber){
    try {
        parser.parseLine("aa 222");
        FAIL();
    } catch (const BadInputExc &exc){
    }
}

// Лишние символы
TEST_F(LineParserT, ExtraSymbols){
    try {
        parser.parseLine("33 222a");
        FAIL();
    } catch (const BadInputExc &exc){
    }
}

