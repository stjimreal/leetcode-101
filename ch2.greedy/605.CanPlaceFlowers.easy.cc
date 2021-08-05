/*
 * @Date: 2021-07-13 15:17:10
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-13 15:57:44
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
 public:
  bool CanPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0)
    {
      return true;
    }
    if (flowerbed.empty()) {
      return false;
    }
    if (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) {
      return true;
    }

    int i = 0, capacity;
    bool res = false;
    while (i < flowerbed.size()) {
      capacity = 0;
      if (flowerbed[i] == 1) {
        ++i;
      }
      while (i < flowerbed.size() && flowerbed[i] == 0) {
        if (i == 0 || i == flowerbed.size() - 1) {
          ++capacity;
        }
        ++i;
        ++capacity;
      }
      n -= (capacity - 1) >> 1;
      if (n <= 0) {
        res = true;
        break;
      }
    }

    return res;
  }
};

int main() 
{
  int m;
  scanf("%d", &m);
  vector<int> flowerbed(m, 0);
  for (size_t i = 0; i < flowerbed.size(); ++i)
  {
    scanf("%d", &flowerbed[i]);
  }
  int n;
  scanf("%d", &n);

  Solution s;
  auto res = s.CanPlaceFlowers(flowerbed, n);
  printf("%d\n", res);
}