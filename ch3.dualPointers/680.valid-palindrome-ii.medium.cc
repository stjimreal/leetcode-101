/*
 * @Date: 2021-07-14 13:54:39
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-14 14:34:24
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* 

 不要总是尝试用局部最优解去概括所有情况，这样不严谨，容易出错！

 */
class Solution
{
private:
  
public:
  Solution();
  ~Solution();
  bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s[i] == s[j]) {
        i++;
        j--;
      } else {
        return false;
      }
    }
    return true;
  }
  bool validPalindrome(string s) {
    bool gate = false;
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s[i] == s[j]) {
        i++;
        j--;
      } else {
        if (!gate) {
          gate = true;
          return  isPalindrome(s.substr(i + 1, j - i)) || 
                  isPalindrome(s.substr(i, j - i));
        } else {
          return false;
        }
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

int main()
{
  Solution s;
  string str;
  cin>>str;
  auto res = s.validPalindrome(str);
  printf("%d\n", res);
}