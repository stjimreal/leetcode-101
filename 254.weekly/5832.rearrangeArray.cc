/*
 * @Date: 2021-08-15 10:42:50
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-15 11:54:03
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

/* 1 2 3 4 5 6 7 */
/* 1 2 4 3 7 5 6 */
/* 0 2 6 7 9 */
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int bucket[100005] = {0};
        for (auto num: nums) {
            bucket[num]++;
        }
        int index = 0;
        for (int i = 0; i < 100005; ++i) {
            if (bucket[i] > 0) {
                nums[index++] = i;
            }
        }
        

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    
    return 0;
}
