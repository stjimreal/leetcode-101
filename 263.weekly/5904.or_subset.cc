/*
 * @Date: 2021-10-17 10:58:15
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-17 11:20:44
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cnt = 0;
    int maxi = 0;
    int num = 0;
    int len;
    void dfs(vector<int>& nums, int index) {
        if (index == len) {
            if (num > maxi) {
                cnt = 1;
            } else if (num == maxi) {
                ++cnt;
            } 
            cout<<endl;
            return; 
        }

        for (int i = index; i < len; ++i) {
            int sv = maxi;
            cout<<nums[i]<<" ";
            maxi |= nums[i];
            dfs(nums, i + 1);
            maxi = sv;
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        this->len = nums.size();
        dfs(nums, 0);
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    // cout<<jiecheng(16)<<endl;

    return 0;
}
