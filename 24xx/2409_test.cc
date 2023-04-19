#include "2409.h"
#include "../tests.h"

int main() {
    std::vector<case_t<int, std::string_view, std::string_view, std::string_view, std::string_view>> cases{
            {"case 1", {"08-15", "08-18", "08-16", "08-19"}, 3},
            {"case 2", {"10-01", "10-31", "11-01", "12-31"}, 0},
            {"case 3", {"01-15", "10-28", "08-05", "12-31"}, 85},
    };

    return run_tests(cases, Solution::countDaysTogether);
}
