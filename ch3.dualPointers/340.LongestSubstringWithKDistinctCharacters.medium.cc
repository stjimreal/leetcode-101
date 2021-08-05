/*
 * @Date: 2021-08-05 22:11:32
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-05 23:14:05
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution();
    ~Solution();
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i = 0, j = 0;
        int max_length = -1;
        int bag = 0;
        bool cnt[256] = {0};
        int  pos[256];
        memset(pos, 255, sizeof(int) * 256);
        while (true) {
            while (bag <= k && j < s.length()) {
                if (!cnt[s[j]]) {
                    // printf("here %c %d\n", s[j], bag);
                    cnt[s[j]] = true;
                    ++bag;
                }
                pos[s[j]] = j;
                ++j;
            }
            if (bag < k) {
                return max_length < 0? s.length(): max_length;
            } else if (bag == k) {
                max_length = max(max_length, j - i);
                return max_length;
            }
            cnt[s[--j]] = false;
            pos[s[j]] = UINT_MAX;
            bag--;
            // cout<<"j = "<<j<<endl;
            // cout<<s.substr(i, j - i)<<endl;
            max_length = max(max_length, j - i);
            while (i <= j && i != pos[s[i]]) {
                ++i;
            }
            // cout<<"i = "<<i<<endl;
            cnt[s[i]] = false;
            pos[s[i++]] = UINT_MAX;
            bag--;
        }
    }
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main(int argc, char const *argv[])
{
    auto s = Solution();
    auto res = s.lengthOfLongestSubstringKDistinct(string("aa"), 1);
    cout<<res<<endl;
    return 0;
}
