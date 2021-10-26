/*
 * @Date: 2021-09-22 01:24:44
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-09-22 13:05:10
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
 private:
    const static int N = 205;
    const static int M = 105;
    int dp[N];
    bool m[M];
    Solution(const Solution&) = delete;
    Solution& operator =(const Solution&) = delete;
 public:
    Solution(){
        bzero(dp, N * sizeof(int));
        bzero(m, sizeof(bool) * M);
    }
    int doubleEleven(vector<int> &items) {
        sort(items.begin(), items.end());
        for (int i = 1; i <= 200; ++i) {
            auto mini = -1;
            for (int j = 0; j < items.size(); ++j) {
                if (i >= items[j] && !m[j] && 
                abs(items[j] + dp[i - items[j]] - i) < abs(dp[i] - i)) {
                    dp[i] = items[j] + dp[i - items[j]];
                    mini = j;
                }
            }
            if (mini > 0) {
                m[mini] = true;
            } else {
                dp[i] = dp[i - 1];
            }
            
        }
        for (int i = 1; i <= 200; ++i) {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        return dp[200];
    }

    int packageEleven(vector<int> &items) {
        dp[0] = 1;
        for (int j = 0; j < items.size(); ++j) {
            for (int i = 200 - items[j]; i >= 0; --i) {
                if (dp[i]==1) dp[i + items[j]] = 1;
            }
            for (int i = 1; i <= 200; ++i) {
            cout<<dp[i]<<" ";
            }
            cout<<endl;
        }
        int i = 200;
        for (; i > 0 && dp[i] == 0; --i);

        return i;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> items{14, 28, 36, 79, 25, 34, 23, 65, 22, 96, 107, 88};
    auto res = Solution().packageEleven(items);
    cout<<res<<endl;
    return 0;
}
