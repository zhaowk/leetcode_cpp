#include "0233.h"
#include "../tests.h"
#include <iostream>

int main() {
    std::vector<case_t<int, int>> cases{
            {"case 1", 1, 1},
            {"case 2", 10, 2},
            {"case 3", 100, 21},
            {"case 4", 1000, 301},
            {"case 5", 10000, 4001},
            {"case 6", 2, 1},
            {"case 7", 20, 12},
            {"case 8", 200, 140},
            {"case 9", 2000, 1600},
            {"case 10", 20000, 18000},
            {"case 11", 3, 1},
            {"case 12", 30, 13},
            {"case 13", 9, 1},
            {"case 14", 90, 19},
    };

    return run_tests(cases, Solution::countDigitOne);
}
