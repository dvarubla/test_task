#pragma once

#include <vector>
#include <cstdint>

namespace test_task_main {
    class BinomialCalculator {
    private:
        /*
         * В матрице хранится сжатый треугольник Паскаля в виде:
         * 2
         * 3
         * 4 6
         * 5 10
         * 6 15 20
         * 7 21 35
         * и так далее
         */
        std::vector<uint32_t> _matrix;
        /*
         * Для каких максимальных k были посчитаны значения, для каждого n
         * (строки треугольника)
         * Чтобы не хранить начальные отрицательные значения, прибавляем дополнительно единицу
         */
        std::vector<uint32_t> _maxKForLines;
        /*
         * Сколько строк в треугольнике полностью заполнено
         */
        uint_fast32_t _numFilledLines;
        /*
         * Вычисляет индекс в матрице выше по индексам i и j, соответствующим n и k
         */
        uint32_t getMatrixIndex(uint_fast32_t i, uint_fast32_t j);
    public:
        BinomialCalculator();
        /*Вычислить значение C(n, k)*/
        uint_fast32_t calc(uint32_t n, uint32_t k);
    };
}
