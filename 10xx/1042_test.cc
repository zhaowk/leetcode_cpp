#include "1042.h"
#include "../tests.h"

int main() {
    std::vector<case_t<vector<int>, int, vector<vector<int>>>> cases{
            {"case 1", {3, {{1,2},{2,3},{3,1}}}, {1,2,3}},
            {"case 2", {4, {{1,2},{3,4}}}, {1,2,1, 2}},
    };

    return run_tests(cases, Solution::gardenNoAdj);
}
