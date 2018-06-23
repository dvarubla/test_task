#include <gtest/gtest.h>
#include <BinomialCalculator.h>

using test_task_main::BinomialCalculator;

//Проверка работы класса-калькулятора
class BinomialCalculatorT: public ::testing::Test {
public:
    BinomialCalculator calc;
    BinomialCalculatorT() = default;
};

//Проверям на значениях из треугольника Паскаля
TEST_F(BinomialCalculatorT, TrianglePart){
    std::vector<std::vector<uint_fast32_t>> triangle = {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
            {1, 5,10,10, 5, 1},
            {1, 6,15,20,15, 6, 1},
            {1, 7,21,35,35,21, 7, 1},
            {1, 8,28,56,70,56,28, 8, 1}
    };
    for(uint_fast32_t i = 0; i < triangle.size(); i++){
        for (uint_fast32_t j = 0; j <= i; j++) {
            EXPECT_EQ(calc.calc(i, j), triangle[i][j]);
        }
    }
}

//Проверям какое-то относительно большое число
TEST_F(BinomialCalculatorT, MediumValue){
    EXPECT_EQ(calc.calc(40, 11), 2311801440);
}

//Вычисляем какое-то относительно большое число, затем c меньшим k и с тем же n
TEST_F(BinomialCalculatorT, MediumValueThenSmallerKSameN){
    calc.calc(40, 11);
    EXPECT_EQ(calc.calc(40, 8), 76904685);
}

//Вычисляем какое-то относительно большое число, затем с меньшим n и k
TEST_F(BinomialCalculatorT, MediumValueThenSmallerNK){
    calc.calc(40, 11);
    EXPECT_EQ(calc.calc(30, 4), 27405);
}

//Вычисляем какое-то относительно большое число, затем с меньшим n и большим k
TEST_F(BinomialCalculatorT, MediumValueThenSmallerNBiggerK){
    calc.calc(40, 11);
    EXPECT_EQ(calc.calc(35, 15), 3247943160);
    EXPECT_EQ(calc.calc(31, 17), 265182525);
}
