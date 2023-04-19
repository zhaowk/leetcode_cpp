#pragma once
#include <vector>
using std::vector;
class Solution {
public:
    static int sumOfBeauties(vector<int>& nums) {
        std::vector<int> mxa(nums.size());
        std::vector<int> mia(nums.size());
        mxa[0] = nums[0];
        mia[nums.size()-1] = nums[nums.size()-1];
        for (int i = 1; i < nums.size(); ++i) {
            mxa[i] = std::max(mxa[i-1], nums[i]);
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            mia[i] = std::min(mia[i+1], nums[i]);
        }

        int result = 0;
        for (int i = 1; i < nums.size()-1; ++i) {
            if (mxa[i-1] < nums[i] && nums[i] < mia[i+1]) {
                result += 2;
            } else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                ++result;
            }
        }
        return result;
    }
};
