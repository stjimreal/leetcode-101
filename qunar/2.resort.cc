/*
 * @Date: 2021-10-13 19:18:37
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-13 19:36:27
 */
/* 

字符重排序
时间限制： 3000MS
内存限制： 589824KB
题目描述：
给定一个只包含大小写英文字母的字符串，需要将字符串中出现的字符按照一定的规则重新排序后输出。

排序规则如下：

1. 首先按照字符串里字符出现的频率降序排列

2. 对于频率相同的字符，则按照先大写后小写的顺序排列

3. 对于频率相同且大小写相同的字符，则按照字母的顺序排序，即 a/A 排在最前，z/Z 排在最后，中间的字母以此类推。



输入描述
baAbb

输出描述
bbbAa


样例输入
baAbb
样例输出
bbbAa

 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int cnt[256];
    bzero(cnt, 256 * sizeof(int));
    vector<pair<char, int>> v;
    char ch;
    int len = 0;
    while (cin>>ch) {
        cnt[(int)ch]++;
        ++len;
    }
    for (char i = 0; i < 26; ++i) {
        v.push_back(pair<char, int>{i + 'a', cnt[i + 'a']});
        v.push_back(pair<char, int>{i + 'A', cnt[i + 'A']});
    }
    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    string s;
    for (int i = 0; i < v.size(); ++i ) {
        pair<char,int> p = v[i];
        s += string(p.second, p.first);
    }
    cout<<s<<endl;
    return 0;
}