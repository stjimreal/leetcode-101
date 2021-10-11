/*
 * @Date: 2021-10-09 20:29:15
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-11 17:33:28
 */
#include <iostream>
#include <vector>

using namespace std;

const int N = 10005;
vector<int> bottle{1,5,10,20,50,100};
int main() {
    unsigned long dp[N];
    int n;
    cin>>n;
    if (n < 1) {
        cout<<0<<endl;
        return 0;
    }
    memset(dp, 0, N * sizeof(unsigned long));
    for (int i = 0; i <= n; ++i) {
        dp[i] = 1;
    }
    for (int i = 1; i < 6; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[j] = (j >= bottle[i]? dp[j - bottle[i]]: 0) + dp[j];
            cout<<dp[j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[n]<<endl;
    return 0;
}