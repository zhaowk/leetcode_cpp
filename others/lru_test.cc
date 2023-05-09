#include <vector>
#include <any>
#include "lru.h"
#include "../tests.h"

typedef std::tuple<int,int> put_arg;

int main() {
    auto _get = [](LruCache<int, int>* cache, std::any&& arg) {
        return cache->get(std::any_cast<int>(arg)).value_or(-1);
    };

    auto _put = [](LruCache<int, int>* cache, std::any&& args) {
        return std::apply([cache](int k, int v) {cache->put(k, v); return 0;}, std::any_cast<put_arg>(args));
    };

    std::vector<case_s<LruCache<int,int>, int, std::any>> cases = {
            {
                    .name = "lru capacity: 2",
                    .obj = new LruCache<int, int>(2),
                    .cases = {
                            {"put 1, 1", _put, 0, put_arg{1,1}},
                            {"put 2, 2", _put, 0, put_arg{2,2}},
                            {"get 1: 1", _get, 1, 1},
                            {"put 3, 3", _put, 0, put_arg{3,3}},
                            {"get 2:-1", _get, -1, 2},
                            {"put 4, 4", _put, 0, put_arg{4,4}},
                            {"get 1:-1", _get, -1, 1},
                            {"get 3: 3", _get, 3, 3},
                            {"get 4: 4", _get, 4, 4},
                    },
            }
    };
    return run_tests_c(cases);
}
