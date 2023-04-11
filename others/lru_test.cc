#include <iostream>
#include "lru.h"

struct cases_t {
    int capacity{};
    // tuple: <put?, arg1, arg2|want>
    std::vector<std::tuple<bool, int, int>> args{};
};

int main() {
    std::vector<cases_t> cases = {
            {
                2,
                {
                        {true, 1, 1},
                        {true, 2, 2},
                        {false, 1, 1},
                        {true, 3, 3},
                        {false, 2, -1},
                        {true, 4, 4},
                        {false, 1, -1},
                        {false, 3, 3},
                        {false, 4, 4},
                }
            }
    };

    for (auto &[cap, args] : cases) {
        LruCache<int, int> cache(cap);
        for (auto &[put, arg1, arg2] : args) {
            if (put) {
                cache.put(arg1, arg2);
            } else {
                if (auto got = cache.get(arg1).value_or(-1); got != arg2) {
                    std::cerr << "test failed! want: " << arg2 << " got: " << got << std::endl;
                    return -1;
                }
            }
        }
    }

    return 0;
}
