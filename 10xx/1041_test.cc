
#include "1041.h"
#include <iostream>

int main() {
    std::vector<std::tuple<std::string, bool> > cases{
            {"GGLLGG", true},
            {"GG", false},
            {"GL", true},
    };

    for (auto &[arg, result] : cases) {
        if (auto got = Solution::isRobotBounded(arg); got != result) {
            std::cerr << "failed! want: " << result << " got: " << got << std::endl;
            return -1;
        }
    }

    return 0;
}
