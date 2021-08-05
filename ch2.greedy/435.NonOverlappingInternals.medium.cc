/*
 * @Date: 2021-07-13 14:33:07
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-13 15:07:17
 */
#include <iostream>
#include <vector>

using namespace std;


/** 
  * 滑动窗口 + 贪心区间
  * 
  * 求最少的移除区间个数，等价于尽量多保留不重叠的区间。
  * 在选择要保留区间时，区间的结尾十分重要：选择的区间结
  * 尾越小，余留给其它区间的空间就越大，就越能保留更多的
  * 区间。因此，我们采取的贪心策略为，优先保留结尾小且不
  * 相交的区间。
  * 
  */
class PairCompare
{
public:
  bool operator()(const vector<int> &a, const vector<int> &b) const {
    return a[1] < b[1];
  }
};

class Solution
{
private:
  
public:
  Solution();
  ~Solution();

  int NonOverlappingInernals(vector<vector<int> > segments) 
  {
    sort<vector<int>, PairCompare>(segments.begin(), segments.end(), PairCompare());
    int prev = segments[0][1], removed = 0;
    for (int i = 1; i < segments.size(); ++i)
    {
      if (segments[i][0] < prev) {
        removed++;
      } else {
        prev = segments[i][1];
      }
    }
    return removed;
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
  vector<vector<int> > segments;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    vector<int> sec(2, 0);
    scanf("%d %d", &sec[0], &sec[1]);
    segments.push_back(sec);
  }
  auto res = s.NonOverlappingInernals(segments);
  printf("%d\n", res);
}
