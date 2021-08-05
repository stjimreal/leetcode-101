/*
 * @Date: 2021-07-13 16:38:20
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-13 19:52:24
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/* 

  字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
  返回一个表示每个字符串片段的长度的列表。

  示例：

  输入：S = "ababcbacadefegdehijhklij"
  输出：[9,7,8]
  解释：
  划分结果为 "ababcbaca", "defegde", "hijhklij"。
  每个字母最多出现在一个片段中。
  像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
   

  提示：

  S的长度在[1, 500]之间。
  S只包含小写字母 'a' 到 'z' 。

 */
class Solution{
public:
  vector<int> partitionLabels(string s) {
    vector<int> pos(26, 0), res;
    int end;
    for(int i = 0; i < s.length(); ++i) {
      pos[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.length();i = end + 1) {
      end = pos[s[i] - 'a'];
      for (int j = i; j < end; ++j) {
        end = max(end, pos[s[j] - 'a']);
      }
      // printf("%c %d\n", s[end], end);
      res.push_back(end - i + 1);
    }
    return res;
  }
};

int main()
{
  Solution s;
  auto res = s.partitionLabels("ababcbacadefegdehijhklij");
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, ","));
  cout<<endl;
}