#include "1172.h"
#include <any>
#include "../tests.h"
//["DinnerPlates","push","push","push","push","push","popAtStack","push","push",
//"popAtStack","popAtStack","pop","pop","pop","pop","pop"]
//[[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
int main() {
    auto _push = [](DinnerPlates* dp, std::any&& args) {
        dp->push(std::any_cast<int>(args));
        return 0;
    };

    auto _pop = [](DinnerPlates* dp, std::any&& args) {
        return dp->pop();
    };

    auto _popAt = [](DinnerPlates* dp, std::any&& args) {
        return dp->popAtStack(std::any_cast<int>(args));
    };

    std::vector<case_s<DinnerPlates, int, std::any>> cases{
            {
                .name = "case 1: dinner plates 2",
                .obj = new DinnerPlates(2),
                .cases = {
                        {"push 1",  _push, 0, 1},
                        {"push 2",  _push, 0, 2},
                        {"push 3",  _push, 0, 3},
                        {"push 4",  _push, 0, 4},
                        {"push 5",  _push, 0, 5},
                        {"popAt 0",  _popAt, 2, 0},
                        {"push 20",  _push, 0, 20},
                        {"push 21",  _push, 0, 21},
                        {"popAt 0",  _popAt, 20, 0},
                        {"popAt 2",  _popAt, 21, 2},
                        {"pop",  _pop, 5},
                        {"pop",  _pop, 4},
                        {"pop",  _pop, 3},
                        {"pop",  _pop, 1},
                        {"pop",  _pop, -1},
                }
            }
    };

    run_tests_c(cases);
    return 0;
}
