#include "BinomialCalculator.h"

using namespace test_task_main;

BinomialCalculator::BinomialCalculator() : _numFilledLines(0){
}

uint_fast32_t BinomialCalculator::calc(uint32_t n, uint32_t k) {
    // Известные значения
    if(k > n) {
        return 0;
    }
    if(n < 2){
        return 1;
    }

    // Используем симметрию треугольника Паскаля
    if(k > n / 2){
        k = n - k;
    }

    // Ещё одно известное значение
    if(k == 0){
        return 1;
    }

    // Приводим к нужному виду, для сжатого треугольника
    n -= 2;
    k--;

    // Индекс в матрице для итогового значения
    uint_fast32_t resultIndex = getMatrixIndex(n, k);

    // Увеличиваем размеры контейнеров
    if(resultIndex >= _matrix.size()){
        _matrix.resize(resultIndex + 1, 0);
    }
    if(n >= _maxKForLines.size()){
        _maxKForLines.resize(n + 1, 0);
    }
    // Если уже посчитано
    if(_matrix[resultIndex] != 0){
        return _matrix[resultIndex];
    }

    for(uint_fast32_t i = _numFilledLines; i <= n; i++){
        // Значение k для текущей строки, +1 для того, чтобы не хранить отрицательные значения
        uint_fast32_t kForLine = std::min<uint_fast32_t>(i / 2, k) + 1;
        // Если больше k, для которого всё посчитано
        if(kForLine > _maxKForLines[i]){
            // Позиция в строке, в которую будем записывать значения
            uint_fast32_t targetLineIndex = getMatrixIndex(i, _maxKForLines[i]);
            // Граничные значения
            if(_maxKForLines[i] == 0){
                _matrix[targetLineIndex] = static_cast<uint32_t>(2 + i);
                _maxKForLines[i]++;
                targetLineIndex++;
            }
            // Не граничные значения
            if(kForLine != 1) {
                // Начальный индекс предыдущей строки, который нужен для расчётов
                uint_fast32_t prevLineIndex = getMatrixIndex(i - 1, _maxKForLines[i] - 1);
                // Максимальный индекс предыдущей строки, относительно начального
                uint_fast32_t prevLineMaxJ = ((i - 1) / 2) - (_maxKForLines[i] - 1);
                // Сколько значений нужно вычислить
                uint_fast32_t numVals = kForLine - _maxKForLines[i];
                for (uint_fast32_t j = 0; j < numVals; j++) {
                    // Расчёт по известной формуле
                    _matrix[targetLineIndex + j] =
                            _matrix[prevLineIndex + j] +
                            ((j == prevLineMaxJ) ? _matrix[prevLineIndex + j] : _matrix[prevLineIndex + j + 1]);
                }
                // Обновляем максимальное значение
                _maxKForLines[i] = static_cast<uint32_t>(kForLine);
            }
            // Если текущая строка полностью заполнена
            if(kForLine == (i / 2) + 1){
                _numFilledLines++;
            }
        }
    }
    return _matrix[resultIndex];
}

uint32_t BinomialCalculator::getMatrixIndex(uint_fast32_t i, uint_fast32_t j) {
    //Сначала находим строку треугольника, потом прибавляем j
    i++;
    uint_fast32_t t = (i - ((i - 1) % 2)) / 2;
    uint_fast32_t iPart = (t + 1) * t + 1;
    iPart += ((i - 1) % 2) * (i / 2);
    return static_cast<uint32_t>(iPart + j - 1);
}
