#pragma once
#include <vector>
using std::vector;
class Solution {
public:
    static vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> maps(n+1);

        for (auto path : paths) {
            maps[path[0]].push_back(path[1]);
            maps[path[1]].push_back(path[0]);
        }

        vector<int> result(n);
        for (auto i = 0; i < result.size(); ++i) {
            int tmp = 0;
            for (auto index : maps[i+1]) {
                if (result[index-1] > 0) {
                    tmp |= 1 << (result[index-1] - 1);
                }
            }
            result[i] = findOne(tmp);
        }
        return result;
    }

    static int findOne(int t) {
        if ((t & 1) == 0) {
            return 1;
        } else if ((t & 2) == 0) {
            return 2;
        } else if ((t & 4) == 0) {
            return 3;
        } else {
            return 4;
        }
    }
};
