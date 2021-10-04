/*
 * @Date: 2021-09-22 13:54:06
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-09-22 14:36:00
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

const int N = 1005;
int map[N][N] = {
    {1,1,1,1,1,1,1,0,1,1,1},
    {1,0,0,1,0,1,1,1,0,1,0},
    {0,0,1,0,0,0,0,0,1,0,0},
    {1,0,0,1,0,0,1,0,0,1,1},
    {1,1,0,0,1,0,0,0,0,0,1},
    {0,1,0,1,1,1,0,1,0,1,0},
    {0,0,1,1,1,0,1,0,0,1,1},
    {0,1,0,1,0,0,1,1,0,0,1},
    {1,1,0,0,1,0,1,1,1,0,1},
};
int m = 9;
int n = 11;

int route[] = {-1,0,1,0,-1};
int res = 0;
int max_area = 0;

void recurCnt(int x, int y, int &area) {
    if (x < 0 || x >= m || y < 0 || y >= n) return;
    if (map[x][y] == 1) {
        map[x][y] = 0;
        area++;
        for (int k = 0; k < 4; ++k) {
            recurCnt(x + route[k], y + route[k + 1], area);
        }
    }
}

void cntIsland() {
    stack<pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == 1) {
                int area = 0;
                recurCnt(i, j, area);
                max_area = max(max_area, area);
                ++res;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cntIsland();
    cout<<max_area<<" "<<res<<endl;
    return 0;
}
