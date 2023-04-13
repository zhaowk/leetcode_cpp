#pragma once
#include <vector>
#include <unordered_map>
using std::vector;

class Solution {
public:
    static int mostFrequentEven(vector<int>& nums) {
        int target = -1, mx = 0;
        std::unordered_map<int, int> m;

        for (auto num : nums) {
            if ((num & 1) == 0) {
                ++m[num];
                if (m[num] > mx) {
                    target = num;
                    mx = m[num];
                } else if (m[num] == mx && num < target) {
                    target = num;
                }
            }
        }

        return target;
    }
};
