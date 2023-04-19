#include "2404.h"
#include "../tests.h"

int main() {
    std::vector<case_t<int, std::vector<int>>> cases {
            {"case 1", {{0, 1, 2, 2, 4, 4, 1}}, 2},
            {"case 2", {{29, 47, 21, 41, 13, 37, 25, 7}}, -1},
    };

    return run_tests(cases, Solution::mostFrequentEven);
}
