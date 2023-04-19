#include "2012.h"
#include "../tests.h"

int main() {
    std::vector<case_t<int, std::vector<int>>> cases{
            {"case 1", {{1, 2, 3}}, 2},
            {"case 2", {{2, 4, 6, 4}}, 1},
            {"case 3", {{3, 2, 1}}, 0},
    };

    return run_tests(cases, Solution::sumOfBeauties);
}
