/*
 * @Date: 2021-08-10 14:35:00
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-10 14:41:50
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        if (nums.size() == 3) {
            if (nums[2] - nums[1] == nums[1] - nums[0])
                return 1;
            else
                return 0;
        }
        int calc = 0;
        vector<int> res;
        vector<bool> flag(nums.size(), false);
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (flag[i]) continue;
            flag[i] = true;
            auto delta  = nums[i + 1] - nums[i];
            int cnt = 1;
            for (int j = i; j < nums.size() - 1; ++j) {
                if (nums[j + 1] - nums[j] == delta) {
                    flag[j] = true;
                    ++cnt;
                } else {
                    break;
                }
            }
            if (cnt < 3) {
                flag[i + 1] = false;
            } else {
                res.push_back(cnt);
            }
        }
        for (auto cnt: res) {
            /* 4: 1 + 2  5: 1 + 2 + 3 */
            if (cnt == 3) {
                calc += 1;
            } else {
                calc += (cnt - 2) * (cnt - 1) / 2;
            }
        }
        return calc;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4};
    auto res = Solution().numberOfArithmeticSlices(nums);
    cout<<res<<endl;
    return 0;
}
