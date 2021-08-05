/*
 * @Date: 2021-07-14 02:52:38
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-14 03:03:59
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  
public:
  Solution();
  ~Solution();
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int merged_ptr = nums1.size() - 1;
    --m; --n;
    while (m >= 0 && n >= 0) {
      nums1[merged_ptr--] = nums1[m] >= nums2[n]? nums1[m--]: nums2[n--];
    }
    if (n >= 0) {
      copy(nums2.begin(), nums2.begin() + n + 1, nums1.begin());
    }
  }
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

/* 
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
 */
int main()
{
  vector<int> nums1{2,3,4,0,0,0}, nums2{1,5,6};
  Solution s;
  s.merge(nums1, 3, nums2, 3);
  copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, ","));
  cout<<endl;
}