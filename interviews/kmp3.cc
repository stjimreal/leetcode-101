/*
 * @Date: 2021-08-25 20:45:46
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-25 20:55:28
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> buildNext(const string &substr) {
    auto length = substr.length();
    vector<int> next(length, -1);
    int i = 0, j = -1;
    while (i < length)
    {
        if (j == -1 || substr[i] == substr[j]) {
            next[++i] = ++j;
        } else {
            j = next[j];
        }
    }
    return next;
}

vector<int> kmp(const string &s, const string &substr) {
    auto next = buildNext(substr);
    int i = 0, j = 0;
    vector<int> res;
    while (i < s.length()) {
        if (j == substr.length()) {
            res.push_back(i - j);
            j = 0;
        }
        if (j == -1 || s[i] == substr[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    return res;
}

int main() {
    auto res = kmp("asvacfefcsdkknweksske", "a");
    copy(res.begin(),res.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
}