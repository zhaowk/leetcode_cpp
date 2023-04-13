#include "2404.h"
#include <iostream>
#include <string_view>

int main() {
    std::vector<std::tuple<std::string_view, std::vector<int>, int>> cases{
            {"case 1", {0, 1, 2, 2, 4, 4, 1}, 2},
            {"case 2", {29, 47, 21, 41, 13, 37, 25, 7}, -1},
    };

    for (auto &[name, arg, want] : cases) {
        if (auto got = Solution::mostFrequentEven(arg); got != want) {
            std::cerr << name << " test failed! want: " << want << ", got: " << got << std::endl;
            return 1;
        }
    }
    return 0;
}
