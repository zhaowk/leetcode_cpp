#pragma once

#include <string>
class Solution {
    static constexpr int N = 0, E = 1, S = 2, W = 3;
public:
    static bool isRobotBounded(std::string_view instructions) {
        int direct = N;
        std::pair<int, int> position{};
        for (auto c : instructions) {
            switch (c) {
                case 'G':
                    ahead(position, direct);
                    break;
                case 'L':
                    direct = left(direct);
                    break;
                case 'R':
                    direct = right(direct);
                    break;
                default:
                    break;
            }
        }

        return (position.first == 0 && position.second == 0) || direct != N;
    }
    static int left(int d) {
        return (d + 3) % 4;
    }
    static int right(int d) {
        return (d + 1) % 4;
    }

    static void ahead(std::pair<int,int>& position, int direction) {
        switch (direction) {
            case N:
                position.second++;
                break;
            case E:
                position.first++;
                break;
            case S:
                position.second--;
                break;
            case W:
                position.first--;
                break;
            default:
                break;
        }
    }
};
