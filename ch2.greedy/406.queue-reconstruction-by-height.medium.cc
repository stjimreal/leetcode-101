/*
 * @Date: 2021-07-13 20:54:56
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-14 01:41:32
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Compare
{
public:
  bool operator()(vector<int> &a, vector<int> &b) {
    // if (a[0] >= b[0]) {
    //   if (a[1] < b[1]) {
    //     return true;
    //   } else{
    //     return false;
    //   }
    // } else {
    //   return false;
    // }
    return a[0] == b[0]? a[1] < b[1]: a[0] > b[0];
  }
};

class Solution
{
private:
  
public:
  Solution();
  ~Solution();
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort<vector<int>, Compare>(people.begin(), people.end(), Compare());
    vector<vector<int>> res;
    for (auto &pair: people) {
      res.insert(res.begin() + pair[1], pair);
    }
    return res;
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
  auto res = s.reconstructQueue(segments);
  for(auto &v: res) {
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    cout<<endl;
  }
}