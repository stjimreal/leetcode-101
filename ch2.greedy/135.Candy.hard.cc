/*
 * @Date: 2021-07-13 11:28:01
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-13 13:39:18
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
    * 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
    * 个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果
    * ；所有孩子至少要有一个糖果。求解最少需要多少个糖果。
    */
  ~Solutions();
  
  int Candy(std::vector<int> &criteria)
  {
    std::vector<int> candies(criteria.size(), 0);
    for (int i = 0; i < criteria.size(); ++i) {
      if (candies[i] == 0) {
        recurCandy(criteria, i, candies);
      } 
    }
    std::copy(candies.begin(), candies.end(), ostream_iterator<int>(cout, ","));
    cout<<endl;
    int res = 0;
    for(auto cand: candies) {
      res += cand;
    }
    return res;
  }
  int recurCandy(std::vector<int> &criteria, int index, std::vector<int> &candies) {
    if (index < criteria.size() - 1 && criteria[index] > criteria[index + 1]) {
      if (candies[index + 1] > 0) {
        candies[index] = candies[index + 1] + 1;
      } else {
        candies[index] = recurCandy(criteria, index + 1, candies) + 1;
      }
    } else if (index > 0 && criteria[index - 1] < criteria[index]){
      candies[index] = candies[index - 1] + 1;
      recurCandy(criteria, index + 1, candies);
    } else {
      candies[index] = 1;
    }
    return candies[index];
  }


  /**
   * @description: 总结：局部最优解的形式会可能以 相邻 分块 等方式出现，注意多种形式的局部最优解
   * @param {vector<int>} &ratings
   * @return {*}
   */  
  int CandyBestSolu(std::vector<int> &ratings)
  {
    vector<int> cnt(ratings.size(), 1);
    int res = 0;
    for (size_t i = 0; i < ratings.size() - 1; ++i)
    {
      if (ratings[i] < ratings[i + 1]) {
        cnt[i + 1] = cnt[i] + 1;
      }
    }
    for (size_t i = ratings.size() - 1; i > 0; --i)
    {
      if (ratings[i - 1] > ratings[i] && cnt[i - 1] <= cnt[i]) {
        cnt[i - 1] = cnt[i] + 1;
      }
    }
    for(auto cand: cnt) {
      res += cand;
    }

    return res;
  }

};


Solutions::~Solutions()
{

}

int main()
{
  std::vector<int> criteria;
  int n, m, a;
  scanf("%d", &n);
  for (size_t i = 0; i < n; ++i)
  {
    scanf("%d", &a);
    criteria.push_back(a);
  }

  Solutions s;
  auto res = s.CandyBestSolu(criteria);
  printf("%d\n", res);
}