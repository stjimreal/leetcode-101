#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
private:
    
public:
    Solution();
    ~Solution();
    string minWindow(string s, string t);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

string Solution::minWindow(string s, string t) {
    int miniSize;
    int alphablet[256];
    bzero(alphablet, 256 * sizeof(int));
    int min_i;
    int i = 0, j = 0;
    for (int i = 0; i < t.length(); ++i) {
        --alphablet[t[i]];
    }
    for (int i = 0; i < 256; ++i) {
        while (j < s.length() && alphablet[i] < 0) {
            ++alphablet[s[j++]];
        }
        if (j >= s.length() && alphablet[i] < 0) {
            return "";
        }
    }
    miniSize = j - i;
    min_i = i;

    while (true) {
        while (i <= j && alphablet[s[i]] > 0) --alphablet[s[i++]];
        if (j - i < miniSize) {
            miniSize = j - i;
            min_i = i;
        }
        if (i <= j && j < s.length()) {
            --alphablet[s[i++]];
        } else {
            break;
        }
        auto ch = s[i - 1];
        // printf("%c %c\n", ch, s[j]);
        while (j < s.length() && alphablet[ch] < 0) {
            ++alphablet[s[j++]];
        }
        if (j >= s.length() && alphablet[ch] < 0) {
            break;
        }
    }
    return s.substr(min_i, miniSize);
}

int main(int argc, char const *argv[])
{
    auto s = Solution();
    // auto res = s.minWindow("a", "aa");
    // auto res = s.minWindow("ADOBECODEBANC", "ABC");
    auto res = s.minWindow("bba", "ab");
    cout<<res<<endl;
    return 0;
}
