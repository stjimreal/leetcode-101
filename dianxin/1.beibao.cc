/*
 * @Date: 2021-10-09 20:29:15
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-10 18:46:46
 */
#include <iostream>
#include <vector>

using namespace std;

const int N = 10005;
vector<int> bottle{1,5,10,20,50,100};
int main() {
    unsigned long dp[6][N];
    int n;
    cin>>n;
    if (n < 1) {
        cout<<0<<endl;
        return 0;
    }
    memset(dp, 0, N * sizeof(unsigned long));
    for (int i = 0; i < 6; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 6; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (j >= bottle[i]? dp[i][j - bottle[i]]: 0) + dp[i - 1][j];
        }
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j < 6; ++j) {
    //         dp[i] += i >= bottle[j]? dp[i-bottle[j]]: 0;
    //     }
    // }
    cout<<dp[5][n]<<endl;
    return 0;
}