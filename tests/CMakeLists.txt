project(test_task_tests)

# Тестовая библиотека
add_library(testlib INTERFACE)
target_link_libraries(testlib INTERFACE gtest_main gmock)
target_include_directories(testlib INTERFACE ${CURRENT_SRC_DIR} mocks)

# Добавить тест
function(add_tt_test name src)
    add_executable(${name} "${src}")
    target_link_libraries(${name} PUBLIC testlib)
    target_link_libraries(${name} PUBLIC TestTaskMainL)
endfunction()

# Проверка работы класса-калькулятора
add_tt_test(BinomialCalculatorT BinomialCalculatorT.cpp)