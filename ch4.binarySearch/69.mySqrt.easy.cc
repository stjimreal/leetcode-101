/*
 * @Date: 2021-08-09 19:13:28
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-09 20:44:25
 */
#include <iostream>

class Solution {
public:
/* 二分查找和牛顿迭代法 */
    int mySqrt(int x) {
        int beg = 1, end = x;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            int sqrt = x / mid;
            if (sqrt > mid) {
                beg = mid + 1;
            } else if (sqrt == mid) {
                return sqrt;
            } else if (sqrt < mid)
            {
                end = mid - 1;
            }
        }
        return end;
    }

};

int main(int argc, char const *argv[])
{
    int input;
    std::cin>>input;
    auto res = Solution().mySqrt(INT_MAX);
    printf("%d\n", res);
    return 0;
}
    