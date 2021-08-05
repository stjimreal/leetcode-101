/*
 * @Date: 2021-07-14 14:37:20
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-05 21:59:44
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* 

524. 通过删除字母匹配到字典里最长单词
给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，
该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。

示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"

提示：

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s 和 dictionary[i] 仅由小写英文字母组成

 */
class Solution {
public:
    bool hasWords(const string &s, const string &sub_s) {
        int j = 0, len = s.length();
        for (int i = 0; i < sub_s.length(); ++i, ++j) {
            while (s[j] != sub_s[i] && j < len) {
                ++j;
            }
            if (j == len) {
                return false;
            }
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string &s1, const string &s2){
            return s1.length() > s2.length() || (s1.length()==s2.length() &&
                s1 < s2);
        });
        for (auto &sub_s: dictionary) {
            if (hasWords(s, sub_s)) {
                return sub_s;
            }
        }
        return "";
    }
};