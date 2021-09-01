/*
 * @Date: 2021-08-22 20:31:19
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-22 21:32:50
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    const static int N = 15;
    int q[N] = {0};
    int res = 0;
    int n;
public:
    int NQueens(int n);
    void recurNQueens(int a);
};


void Solution::recurNQueens(int a)
{
    if (a > n) {
        ++res;
    }
    for (int j = 1; j <= n; ++j) {
        bool flag = true;
        for (int k = 1; k < a; ++k) {
            if (j == q[k] || abs(a - k) == abs(j - q[k])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            q[a] = j;
            recurNQueens(a + 1);
        }
    }
}

int Solution::NQueens(int n) {
    this->n = n;
    recurNQueens(1);
    return res;
}

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 13; ++i) {
        auto res = Solution().NQueens(i);
        cout<<res<<endl;   
    }
    return 0;
}
