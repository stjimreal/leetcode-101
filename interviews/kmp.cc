/*
 * @Date: 2021-08-19 16:07:58
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-22 22:01:06
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> build(string &substr) {
    vector<int> res(substr.length(), 0);
    int i = 0;
    for (int j = 1; j < substr.length(); ++j) {
        if (substr[i] == substr[j]) {
            res[j] = i++;
        } else {
            res[j] = i;
            i = res[i];
            while (substr[i] != substr[j] && i != 0) {
                i = res[i];
            }
            if (substr[i] == substr[j]) ++j;
        }
        
    }
    return res;
}

int subStr(string &s, string &substr) {
    auto kmp = build(substr);
    copy(kmp.begin(), kmp.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    copy(substr.begin(), substr.end(), ostream_iterator<char>(cout, " "));
    cout<<endl;

    int i = 0, j = 0;
    while (i < s.length()) {
        if (j == substr.length()) {
            return i - j;
        }
        if (s[i] == substr[j]) {
            // cout<<substr[j]<<" ";
            ++j;
        } else {
            j = kmp[j];
            while (s[i] != substr[j] && j != 0) {
                j = kmp[j];
            }
            if (s[i] == substr[j]) ++j;
        }
        ++i;
    }

    return -1;
}

vector<int> buildPMT(string &substr) {
    vector<int> pmt(substr.length(), -1);
    int i = 0, j = -1;
    while (i < substr.length()) {
        if (j == -1 || substr[i] == substr[j]) {
            ++i;
            ++j;
            pmt[i] = j;
        } else {
            j = pmt[j];
        }
    }
    return pmt;
}

int kmp(string &s, string &substr) {
    auto pmt = buildPMT(substr);
    copy(pmt.begin(), pmt.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    copy(substr.begin(), substr.end(), ostream_iterator<char>(cout, " "));
    cout<<endl;
    
    int i = 0, j = 0;
    while (i < s.length()) {
        if (j == substr.length()) {
            return i - j;
        }
        if (j == -1 || s[i] == substr[j]) {
            ++i;
            ++j;
        } else {
            j = pmt[j];
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string s = "asdvefisdcaoacbaoacbaoackfaoacao", substr = "abcabababcabqaqbabcabababaab";
    int res = kmp(s, substr);
    cout<<res<<endl;
    return 0;
}
