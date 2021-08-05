/*
 * @Date: 2021-07-14 10:36:00
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-14 12:01:13
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  int kNumbCharacter = 128;
  bool isSubsession(const vector<int> &lib, const vector<int> &cnt) {
    for (int i = 0; i < kNumbCharacter; ++i) {
      if (lib[i] > cnt[i]) {
        return false;
      }
    }
    return true;
  }
  
public:
  Solution();
  ~Solution();
  string minWindow(string s, string t) {
    vector<int> cnt1(kNumbCharacter, 0), cnt2(kNumbCharacter, 0);
    for(auto ch: s) {
      cnt1[ch]++;
    }
    for(auto ch: t) {
      cnt2[ch]++;
    }
    if (!isSubsession(cnt2, cnt1)) {
      return "";
    }
    cnt1.assign(kNumbCharacter, 0);
    int i = 0, j = 0;
    int sub_i = 1, sub_j = s.length();
    while (i <= j && j < s.length()) {
      while (j < s.length() && !isSubsession(cnt2, cnt1)) {
        cnt1[s[j++]]++;
      }
      while (i <= j && isSubsession(cnt2, cnt1)) {
        cnt1[s[i++]]--;
      }
      if (sub_j - sub_i + 1 > j - i + 1) {
        sub_j = j;
        sub_i = i; 
      }
    }
    return s.substr(sub_i - 1, sub_j - sub_i + 1);
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
  // auto res = s.minWindow("ADOBECODEBANC", "ABC");
    auto res = s.minWindow("a", "a");
  // auto res = s.minWindow("cabwefgewcwaefgcf"
  //                         ,"cae");
  printf("%s\n", res.c_str());
}