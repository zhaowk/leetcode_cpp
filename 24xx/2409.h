#pragma once
#include <string_view>
using std::string_view;

class Solution {
    struct date {
        int m, d;
        constexpr static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool operator<(const date& other) const {
            return this->m < other.m || (m == other.m && d < other.d);
        }

        [[nodiscard]] int distance(const date& other) const {
            if (m == other.m) {
                return other.d - d;
            }

            int r = 0;
            for (int i = m; i < other.m-1; ++i) {
                r += days[i];
            }
            return r + days[m-1] - d + other.d;
        }
    };

public:
    static int countDaysTogether(string_view arriveAlice, string_view leaveAlice, string_view arriveBob, string_view leaveBob) {
        date alice1{}, alice2{}, bob1{}, bob2{};

        sscanf(arriveAlice.data(), "%d-%d", &alice1.m, &alice1.d);
        sscanf(leaveAlice.data(), "%d-%d", &alice2.m, &alice2.d);
        sscanf(arriveBob.data(), "%d-%d", &bob1.m, &bob1.d);
        sscanf(leaveBob.data(), "%d-%d", &bob2.m, &bob2.d);

        if (alice2 < bob1 || bob2 < alice1) {
            return 0;
        }

        return std::max(alice1, bob1).distance(std::min(alice2, bob2)) + 1;
    }
};
