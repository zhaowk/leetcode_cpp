#pragma once

//两个数对 (a, b) 和 (c, d) 之间的 乘积差 定义为 (a * b) - (c * d) 。
//
//例如，(5, 6) 和 (2, 7) 之间的乘积差是 (5 * 6) - (2 * 7) = 16 。
//给你一个整数数组 nums ，选出四个 不同的 下标 w、x、y 和 z ，使数对 (nums[w], nums[x]) 和 (nums[y], nums[z]) 之间的 乘积差 取到 最大值 。
//
//返回以这种方式取得的乘积差中的 最大值 。
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    static int maxProductDifference(vector<int>& nums) {
        std::sort(nums.begin(), nums.begin()+4);
        int mi1 = nums[0], mi2 = nums[1], mx1 = nums[2], mx2 = nums[3];

        for (int i = 4; i < nums.size(); ++i) {
            if (nums[i] <= mi1) {
                mi2 = mi1;
                mi1 = nums[i];
            } else if (nums[i] < mi2) {
                mi2 = nums[i];
            } else if (nums[i] >= mx2) {
                mx1 = mx2;
                mx2 = nums[i];
            } else if (nums[i] > mx1) {
                mx1 = nums[i];
            }
        }
        return mx1*mx2 - mi1*mi2;
    }
};
