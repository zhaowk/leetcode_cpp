#include "1041.h"
#include "../tests.h"

int main() {
    std::vector<case_t<bool, std::string>> cases{
            {"case 1", "GGLLGG", true},
            {"case 2", "GG", false},
            {"case 3", "GL", true},
    };

    return run_tests(cases, Solution::isRobotBounded);
}
