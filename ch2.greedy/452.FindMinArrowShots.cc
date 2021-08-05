/*
 * @Date: 2021-07-13 16:09:41
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-13 16:36:19
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
  1 <= points.length <= 104
  points[i].length == 2
  -2^31 <= x_start < x_end <= 2^31 - 1
 */
class Solution{
 public:
  int FindMinArrowShots(vector<vector<int> >& points) {
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int>&b){
      return a[0] < b[0];
    });
    int arrows = 1, beg = points[0][0], end = points[0][1];
    for(int i = 1; i < points.size(); ++i) {

    /*   
      if (balloon[0] > pos) {
          pos = balloon[1];
          ++ans;
      } 
    */
      if (points[i][0] <= end) {
        beg = points[i][0];
        end = min(end, points[i][1]);
      } else {
        ++arrows;
        beg = points[i][0];
        end = points[i][1];
      }
    }
    return arrows;
  }

};

int main() {
  vector<vector<int> > points;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    vector<int> sec(2, 0);
    scanf("%d %d", &sec[0], &sec[1]);
    points.push_back(sec);
  }
  Solution s;
  auto res = s.FindMinArrowShots(points);
  printf("%d\n", res);
}