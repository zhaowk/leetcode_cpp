#include "1913.h"
#include "../tests.h"

int main() {
    std::vector<case_t<int, std::vector<int>>> cases{
            {"case 1", {{5, 6, 2, 7, 4}}, 34},
            {"case 2", {{4, 2, 5, 9, 7, 4, 8}}, 64},
    };

    return run_tests(cases, Solution::maxProductDifference);
}
