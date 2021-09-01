/*
 * @Date: 2021-08-10 22:13:13
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-10 23:38:03
 */
/* JDK的sort实现： */
/* 哨兵插排 */
/* 荷兰国旗问题 三路快排 */
/* 双pivot 快排 */
/* 划分结构度再归并 */
/* TimSort reverse降序子序列，再merge */
/* 归并排序：使用最多的，稳定排序 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        for (int i = 0; i < nums.size()-1 && nums[i] <= nums[i + 1]; ++i) {
            if (i + 1 >= nums.size() - 1) return;
        }
        int less = -1, great = nums.size() - 1, pivot = 1;
        while (++less <= great && nums[less] < pivot);
        while (great > 0 && nums[great--] > pivot);
        great += 1;
        if (less >= great) return;
        // printf("%d %d\n", less, great);
        for (int k = less; k <= great; ++k) {
            // cout<<k<<endl;
            if (nums[k] == pivot) continue;
            int nk = nums[k];
            if (nums[k] < pivot) {
                nums[k] = nums[less];
                nums[less] = nk;
                ++less;
            } else {
                if (nums[great] == pivot) {
                    nums[k] = nums[great];
                } else if (nums[great] < pivot) {
                    nums[k] = nums[less];
                    nums[less] = nums[great];
                    ++less;
                } else {
                    --k;
                    --great;
                    continue;
                }
                nums[great] = nk;
                --great;
            }
            // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
            // cout<<endl;
            // printf("%d %d\n", less, great);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto v = vector{1,0,2};
    s.sortColors(v);
    return 0;
}
