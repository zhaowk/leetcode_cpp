#pragma once
#include <algorithm>

class Solution {
public:
    static int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        }

        int* results = new int[n+1];
        int max = 1;
        results[0] = 0;
        results[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i & 1) { // odd
                results[i] = results[i/2] + results[i/2+1];
            } else {
                results[i] = results[i/2];
            }
            max = std::max(max, results[i]);
        }
        return max;
    }
};
