#pragma once

//你会得到一个字符串text。你应该把它分成 k 个子字符串(subtext1, subtext2，…， subtextk)，要求满足:
//  * subtext[i] 是 非空字符串
//  * 所有子字符串的连接等于 text ( 即subtext[1] + subtext[2] + ... + subtext[k] == text)
//  * 对于所有 i的有效值( 即1 <= i<= k ) ，subtext[i] == subtext[k - i + 1] 均成立
//返回k可能最大值。

#include <string>
using std::string;
using std::string_view;

class Solution {
public:
    static int longestDecomposition(string_view text) {
        int count = 1;
        size_t front_start = 0, front_end = 1, back_end = text.length(), back_start = back_end - 1;

        while (front_end < back_start) {
            if (equal(text, front_start, front_end, back_start, back_end)) {
                front_start = front_end;
                back_end = back_start;
                count += 2;
            }
            front_end++;
            back_start--;
        }

        // last equal
        if (front_end == back_start && equal(text, front_start, front_end, back_start, back_end)) {
            ++count;
        }

        return count;
    }

    static bool equal(std::string_view str, size_t begin, size_t end, size_t rbegin, size_t rend) {
        return string_view(str.data() + begin, end - begin) == string_view(str.data() + rbegin, rend - rbegin);
    }
};
