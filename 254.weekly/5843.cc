/*
 * @Date: 2021-08-15 10:34:27
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-15 10:40:21
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;


class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (auto patt: patterns) {
            int pos = word.find(patt);
            if (pos < 0) continue;
            ++res;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> patt = {"a", "a", "a"};
    string word = "ab";
    auto res = s.numOfStrings(patt, word);
    cout<<res<<endl;
    return 0;
}
