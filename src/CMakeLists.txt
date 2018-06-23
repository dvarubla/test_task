project(test_task_main)

add_library(TestTaskMainL STATIC BinomialCalculator.cpp BinomialCalculator.h LineParser.cpp LineParser.h BadInputExc.cpp BadInputExc.h)

target_include_directories(TestTaskMainL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_task main.cpp)

target_link_libraries(
        test_task
        TestTaskMainL
)