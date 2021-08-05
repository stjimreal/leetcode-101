/*
 * @Date: 2021-07-14 13:07:14
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-14 14:37:05
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  
public:
  Solution();
  ~Solution();
  bool judgeSquareSum(int c) {
    int j = int(sqrt(c));
    int i = 0;
    while (i <= j)
    {
      int sum = i * i + j * j;
      if (sum > c) {
        --j;
      } else if (sum < c) {
        ++i;
      } else {
        return true;
      }
    }
    return false;
  }
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
  Solution s;
  auto res = s.judgeSquareSum(1);
  cout<<res<<endl;
}