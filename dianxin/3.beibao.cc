/*
 * @Date: 2021-10-09 20:53:07
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-09 21:09:04
 */


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    int num;
    cin>>num;
    vector<int> val(num);
    vector<bool> used(num, false);
    for (int i = 0; i < num; ++i) {
        cin>>val[i];
    }
    cin>>num;
    vector<int> cost(num);
    for (int i = 0; i < num; ++i) {
        cin>>cost[i];
    }
    int res = 0;
    vector<int> dp(n + 1, 0);
    vector<int> propose, resProp;
    for (int i = 1; i < n + 1; ++i) {
        int maxDp = 0;
        int maxIndex = -1;
        for (int j = 0; j < num; ++j) {
            if (i >= cost[j]) {
                // if (dp[i - cost[j]] + val[j] > maxDp) {
                //     maxIndex = j;
                // }
                maxDp = max(maxDp, dp[i - cost[j]] + val[j]);
            }
        }
        propose.push_back(maxIndex);
        dp[i] = maxDp;
        // if (dp[i] > res) {
        //     resProp = std::move(propose);

        // }
        res = max(res, dp[i]);
    }
    // for (auto num: resProp) {
    //     cout<<num<<" ";
    // }
    // cout<<endl;
    cout<<res<<endl;

    return 0;
}