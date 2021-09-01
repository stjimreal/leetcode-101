/*
 * @Date: 2021-08-10 15:18:41
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-10 15:59:48
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        /* 一定是偶数下标 */
        while (l <= r) {
            auto mid = l + (r - l) / 2;
            /* [1,1,2,3,3,4,4,8,8] */
            /*  0 1 2 3 4 5 6 7 8 */
            /* cout<<mid<<" "<<l<<" "<<r<<endl; */
            bool flag1 = mid > 0 && nums[mid] == nums[mid - 1];
            bool flag2 = mid < nums.size() - 1 && nums[mid + 1] == nums[mid];
            if (!(flag1 || flag2)) {
                return nums[mid];
            }
            if ((flag1 && mid % 2 == 0) || (flag2 && mid % 2 == 1)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[0];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v1 = {1,1,3,3,2,4,4,8,8}, v2 = {3,3,7,7,10,11,11};
    vector<int> v3 = {4}, v4 = {1,1,2};
    auto res1 = s.singleNonDuplicate(v1);
    cout<<res1<<endl;
    return 0;
}
