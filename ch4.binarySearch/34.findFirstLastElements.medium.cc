/*
 * @Date: 2021-08-09 20:46:55
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-09 22:36:00
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

int searchLf(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= target) {
            r = mid - 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        }
    }
    return l;
}

int searchRt(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            r = mid - 1;
        } else if (nums[mid] <= target) {
            l = mid + 1;
        }
    }
    return r;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int lower_bound = searchLf(nums, target);
    int upper_bound = searchRt(nums, target);
    if (lower_bound > upper_bound) {
        lower_bound = upper_bound = -1;
    }
    return vector<int>{lower_bound, upper_bound};
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

    auto res = searchRange(nums, target);
    for (auto num: res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
