/*
 * @Date: 2021-08-22 21:33:43
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-22 22:06:47
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// [-1, 0, 0, ]
vector<int> build_next(string substr) {
    vector<int> next(substr.length(), -1);
    int i = 0, j = -1;
    while(i < substr.length()) {
        if (j == -1 || substr[j] == substr[i]) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
    return next;
}

vector<int> kmp(const string &s, const string &substr) {
    auto next = build_next(substr);
    int i = 0, j = 0;
    vector<int> res;
    while (i < s.length()) {
        if (j == -1 || s[i]==substr[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if (j == substr.length()) {
            res.push_back(i - j);
            j = 0;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    auto res = kmp("abcabababcabqaqbabcabababaab", "ab");
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}
