/*
 * @Date: 2021-08-10 10:47:04
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-11 19:33:56
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int quick_select(vector<int>&nums, int l, int r) {
    int partition = nums[l];
    while (l < r)
    {
        while(l < r && nums[r] >= partition) --r;
        nums[l] = nums[r];
        while(l < r && nums[l] <= partition) ++l;
        nums[r] = nums[l];
    }
    nums[l] = partition;
    return l;
}

int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int mid = quick_select(nums, l, r);
        if (mid == k) {
            return k;
        } else if (mid < k) {
            l = mid + 1;
        } else if (mid > k) {
            r = mid - 1;
        }
    }
    return nums[k];
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin>>n>>k;
    vector<int> v;
    while(n--) {
        int num;
        cin>>num;
        v.push_back(num);
    }
    auto res = findKthLargest(v, k);
    cout<<res<<endl;
    return 0;
}
