#include "1646.h"
#include "../tests.h"

int main() {
    std::vector<case_t<int, int>> cases{
            {"case 1", 3, 2},
            {"case 2", 4, 2},
            {"case 3", 7, 3},
    };

    return run_tests(cases, Solution::getMaximumGenerated);
}