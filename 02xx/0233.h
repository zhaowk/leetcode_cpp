#pragma once

class Solution {
public:
    static int countDigitOne(int n) {
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += count(i);
        }
        return total;
    }
private:
    static int count(int i) {
        int c = 0;
        do {
            if (i % 10 == 1) {
                ++c;
            }
            i = i / 10;
        } while(i > 0);
        return c;
    }
};
