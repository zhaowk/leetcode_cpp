#include "0233.h"
#include <iostream>

int main() {
    std::vector<std::tuple<int, int>> cases{
            {1, 1},
            {10, 2},
            {100, 21},
            {1000, 301},
            {10000, 4001},
            {2, 1},
            {20, 12},
            {200, 140},
            {2000, 1600},
            {20000, 18000},
            {3, 1},
            {30, 13},
            {9, 1},
            {90, 19},
    };

    for (auto [arg, want] : cases) {
        if (auto got = Solution::countDigitOne(arg); got != want) {
            std::cerr << "test failed! want: " << want << ", got: " << got << std::endl;
            return -1;
        }
    }

    return 0;
}
