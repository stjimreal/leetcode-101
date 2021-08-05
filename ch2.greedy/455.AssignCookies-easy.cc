/*
 * @Date: 2021-06-30 17:05:30
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-13 11:26:19
 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solutions
{
 private:
  
 public:

  /** 
    * Descrption: 
    * 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
    * 一个饼干，且只有饼干的大小不小于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少
    * 孩子可以吃饱。
    * 
    */
  ~Solutions();
  
  int AssignCookies(std::vector<int> &starvation, std::vector<int> &biscuits)
  {
    sort(starvation.begin(), starvation.end());
    sort(biscuits.begin(), biscuits.end());
    int i = 0, j = 0;
    int i_len = starvation.size();
    int j_len = biscuits.size();
    while (i < i_len && j < j_len) {
      if (starvation[i] <= biscuits[j]) {
        i++;
      }
      j++;
    }
    return i;
  }

};


Solutions::~Solutions()
{

}

int main()
{
  std::vector<int> starvation, biscuits;
  int n, m, a;
  scanf("%d", &n);
  scanf("%d", &m);
  for (size_t i = 0; i < n; ++i)
  {
    scanf("%d", &a);
    starvation.push_back(a);
  }
  for (size_t i = 0; i < m; ++i)
  {
    scanf("%d", &a);
    biscuits.push_back(a);
  }
  
  Solutions s;
  auto res = s.AssignCookies(starvation, biscuits);
  printf("%d\n", res);
}