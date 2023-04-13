#include "1913.h"
#include <string_view>
#include <iostream>
int main() {
    std::vector<std::tuple<std::string_view, std::vector<int>, int>> cases{
            {"case 1", {{5, 6, 2, 7, 4}}, 34},
            {"case 2", {{4, 2, 5, 9, 7, 4, 8}}, 64},
    };

    for (auto &[name, arg, want] : cases) {
        if (auto got = Solution::maxProductDifference(arg); got != want) {
            std::cerr << name << " test failed! want: " << want << ", got: " << got << std::endl;
            return 1;
        }
    }
    return 0;
}