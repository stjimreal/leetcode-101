/*
 * @Date: 2021-07-14 02:41:24
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-14 02:48:00
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
  vector<int> twoSum(vector<int>&& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j) {
      if (numbers[i] + numbers[j] > target) {
        --j;
      } else if (numbers[i] + numbers[j] < target) {
        ++i;
      } else {
        break;
      }
    }
    return vector{i, j};
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
  auto res = s.twoSum(vector{2,3,4}, 6);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, ","));
  cout<<endl;
}