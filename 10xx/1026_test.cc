#include "1026.h"
#include "../tests.h"

int main() {
    std::vector<case_t<int, TreeNode*>> cases{
            {"case 1", buildTree({8, 3, 10, 1, 6, std::nullopt, 14, std::nullopt, std::nullopt, 4, 7, 13}), 7},
            {"case 2", buildTree({1, std::nullopt, 2, std::nullopt, 0, 3}), 3},
    };

    return run_tests(cases, Solution::maxAncestorDiff);
}
