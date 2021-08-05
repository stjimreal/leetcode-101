/*
 * @Date: 2021-07-14 01:53:53
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-05 14:30:29
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
  bool checkPossibility(vector<int>& nums) {
    if (nums.size() <= 2) {
      return true;
    }
    int flag = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] > nums[i]) {
        if ((i + 1 >= nums.size() || nums[i + 1] >= nums[i - 1]) ||
            i < 2 || nums[i - 2] <= nums[i]) {
          flag++;
        } else {
          return false;
        }
      }
      if (flag > 1) {
          return false;
      }
    }
    return true;
  }
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main() {
  vector<int> nums{-1,2,-5,3,4};
  auto res = Solution().checkPossibility(nums);
  printf("%d\n", res);
}