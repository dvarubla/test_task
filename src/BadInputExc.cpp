#include "BadInputExc.h"

test_task_main::BadInputExc::BadInputExc(const std::string &arg) : runtime_error(arg) {}
