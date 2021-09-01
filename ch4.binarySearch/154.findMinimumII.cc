/*
 * @Date: 2021-08-10 15:13:50
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-10 15:16:04
 */
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while(l < r) {
        int mid = l + ((r - l) >> 1);
        if (nums[l] < nums[r]) {
            return nums[l];
        } else if (nums[l] < nums[mid]) {
            l = mid;
        } else if (nums[l] > nums[mid]) {
            r = mid;
        } else {
            l++;
        }
    }
    return nums[l];
}

int main(int argc, char const *argv[])
{
    vector nums = {2,2,2,0,1};
    auto res = findMin(nums);
    cout<<res<<endl;
    return 0;
}
