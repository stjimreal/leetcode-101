/*
 * @Date: 2021-08-09 22:37:09
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-10 12:48:16
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

bool search(vector<int>& nums, int target) {
    int beg = 0, end = nums.size() - 1;
    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        printf("%d\n", mid);
        if (nums[mid] == target) {
            return true;
        } 
        if (nums[mid] == nums[end]) {
            /* 排除一下beg end mid 三者相等的情况，
               无法判断左侧数字是完全相同还是右侧数字
               完全相同 */
            --end;
        } else if (nums[mid] >= nums[beg]) {
            /* 确定一个单增区间进行决策，剩下的补集采用相反决策 */
            if (target >= nums[beg] && target < nums[mid]) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[end]) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int target, k;
    cin>>target>>k;
    vector<int> nums;
    while(k--) {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    auto res = search(nums, target);
    cout<<res<<endl;
    return 0;
}
