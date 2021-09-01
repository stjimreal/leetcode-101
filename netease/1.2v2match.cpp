/*
 * @Date: 2021-08-06 19:04:32
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-06 23:25:46
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>

/**
 * 
 * 2v2匹配
 * 积分，set(0 = q1,1 = q2)
 * 
 *  
 */

using namespace std;

class Solution
{
private:
    int team_sum_, p_bar_;
    int res_;
    void calc_single_gamer(vector<int>, int );
public:
    Solution();
    ~Solution();
    void inline calcSumComp(int sum) {
        if (abs(sum - team_sum_) <= p_bar_) {
            ++res_;
        } 
    }
    int Match2v2() {
        return res_;
    }
};

void Solution::calc_single_gamer(vector<int> single_gamer_array, int single_num) {
    /* 理解有问题 */
    for (int i = 0; i < single_num; ++i) {
        for (int j = i + 1; j < single_num; ++j) {
            // printf("%d %d\n", single_gamer_array[i], single_gamer_array[j]);
            calcSumComp(single_gamer_array[i] + single_gamer_array[j]);
        }
    }
    
}

Solution::Solution(): res_(0)
{
    int q1, q2, x, y;
    vector<int> single_gamer_array;

    scanf("%d %d %d", &q1, &q2, &p_bar_);
    team_sum_ = q1 + q2;
    scanf("%d", &x);
    for (int i = 0; i < x; ++i) {
        scanf("%d %d", &q1, &q2);
        // printf("%d %d\n", q1, q2);
        calcSumComp(q1 + q2);
    }
    scanf("%d", &y);
    single_gamer_array.assign(y, 0);
    for (int i = 0; i < y; ++i) {
        scanf("%d", &single_gamer_array[i]);
    }
    calc_single_gamer(single_gamer_array, y);
}

Solution::~Solution()
{
}
int main(int argc, char const *argv[])
{
    auto s = Solution();
    /* 1000 * 999 / 2 = 4.9 * 10^5 */
    auto res = s.Match2v2();
    printf("%d\n", res);
    return 0;
}
