#include "1023.h"
#include "../tests.h"

int main() {
    std::vector<case_t<std::vector<bool>, std::vector<std::string>, std::string>> cases{
            {"case 1", {{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"}, "FB"}, {true, false, true, true, false}},
            {"case 2", {{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"}, "FoBa"}, {true, false, true, false, false}},
            {"case 3", {{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"}, "FoBaT"}, {false, true, false, false, false}},
            {"case 4", {{"CompetitiveProgramming", "CounterPick", "ControlPanel"}, "CooP"}, {false, false, true}},
            {"case 5", {{"uAxaqlzahfialcezsLfj", "cAqlzyahaslccezssLfj", "AqlezahjarflcezshLfj", "AqlzofahaplcejuzsLfj", "tAqlzahavslcezsLwzfj", "AqlzahalcerrzsLpfonj", "AqlzahalceaczdsosLfj", "eAqlzbxahalcezelsLfj"}, "AqlzahalcezsLfj"}, {true, true, true, true, true, true, true, true}},
    };

    return run_tests(cases, Solution::camelMatch);
}
