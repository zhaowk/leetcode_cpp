#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;
class Solution {
public:
    static vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result(queries.size(), false);
        vector<string> ps;
        int i = 0;
        for (int j = 0; j < pattern.size(); ++j) {
            if (pattern[j] >= 'A' && pattern[j] <= 'Z') {
                if (i < j) {
                    ps.push_back(pattern.substr(i, j - i));
                }
                i = j;
            }
        }

        ps.push_back(pattern.substr(i));
        for (int j = 0; j < queries.size(); ++j) {
            result[j] = match(queries[j], ps);
        }
        return result;
    }

    static bool match(std::string_view s, const vector<string>& ps) {
        int i = 0;  // string `s` index

        for (const auto& pattern : ps) {
            if (pattern.empty()) {
                continue;
            }
            int j = 0;
            if (pattern[0] >= 'A' && pattern[0] <= 'Z') { // 大写字母开头
                for (; s[i] >= 'a' && s[i] <= 'z'; i++);  // 跳过多余的小写字母

                if (i >= s.size() || s[i] != pattern[0]) { // 匹配大写字母
                    return false;
                }
                // 匹配到大写字母， 指针移动
                ++i;
                ++j;
            }

            for (; j < pattern.size(); ++j) { // O(N)， 匹配小写字母串
                for (; i < s.size(); ++i) {
                    if (s[i] == pattern[j]) {
                        ++i;
                        break;
                    } else if (s[i] >= 'A' && s[i] <= 'Z') {
                        return false;
                    }
                }
            }

            if (j < pattern.size()-1) { // 未匹配完成
                return false;
            }
        }

        // 未匹配的大写字母 ==> 失败
        for (; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                return false;
            }
        }
        return true;
    }
};
