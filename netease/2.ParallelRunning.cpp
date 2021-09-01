/*
 * @Date: 2021-08-06 19:04:32
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-06 20:56:59
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;





class Solution
{
private:
    
public:
    Solution();
    ~Solution();
    int ParallelRunning(vector<int> &way1, int same_t, int high_t, int low_t, int switch_t);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::ParallelRunning(vector<int> &way1, 
                                int same_t, int high_t, int low_t, int switch_t) {
    // hight_t + switch_t VS. low_t, low_t + switch_t VS. high_t
    // 三角形数：不用换
    // 非三角形数：switch_t 长 不用换；
    //  t = t + min(next_this_way, switch_way + other_way);
    int len = way1.size();
    vector<int> virtual_way(len);
    for (int i = 0; i < len; ++i) {
        virtual_way[i] = 4 - way1[i];
    }
    int timer = 0;
    bool flag = true;
    bool case1 = high_t + low_t <= switch_t || (high_t + switch_t > low_t && low_t + switch_t > high_t); // 不用换
    bool case2 = (!case1) && high_t + switch_t < low_t;
    bool case3 = (!case1) && low_t + switch_t < high_t;
    vector<int>* way = &way1;
    int prev = (*way)[0];

    for (int i = 1; i < len; ++i) {
        if (case1) {
            if (prev == way1[i]) {
                timer += same_t;
            } else if (prev > way1[i]) {
                timer += low_t;
            } else if (prev < way1[i]) {
                timer += high_t;
            }
        } else if (case2) {
            if (prev > (*way)[i]) {
                timer += switch_t + high_t;
                flag = !flag;
                way = flag? &way1: &virtual_way;
            } else if (prev < (*way)[i]) {
                timer += high_t;
            } else if (prev == (*way)[i]) {
                timer += same_t;
            }
        } else if (case3) {
            if (prev < (*way)[i]) {
                timer += switch_t + low_t;
                flag = !flag;
                way = flag? &way1: &virtual_way;
            } else if (prev > (*way)[i]) {
                timer += low_t;
            } else if (prev == (*way)[i]) {
                timer += same_t;
            }
        }
        prev = (*way)[i];
        // printf("%d\n", timer);
    }
    return timer;
}


int main(int argc, char const *argv[])
{
    auto s = Solution();
    int N, T1, T2, T3, T4;
    scanf("%d %d %d %d %d", &N, &T1, &T2, &T3, &T4);
    vector<int> v(N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }
    auto time = s.ParallelRunning(v, T1, T2, T3, T4);
    printf("%d\n", time);
    return 0;
}
