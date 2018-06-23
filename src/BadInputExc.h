#pragma once

#include <stdexcept>

namespace test_task_main {
    class BadInputExc : public std::runtime_error{
    public:
        BadInputExc(const std::string &arg);

    };
}
