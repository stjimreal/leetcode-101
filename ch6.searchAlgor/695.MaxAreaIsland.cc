/*
 * @Date: 2021-09-01 17:29:35
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-09-01 18:07:06
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <stack>

using namespace std;

/* 

    [
        [1,0,1,1,0,1,0,1],
        [1,0,1,1,0,1,1,1],
        [0,0,0,0,0,0,0,1],
    ]

 */
int maxAreaOfIsland(vector<vector<int>> grid) {
    int direction[] = {-1, 0, 1, 0, -1};
    // int 
    int n = grid.size(), m = n?grid[0].size(): 0, area = 0, local_area, i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                local_area = 1;
                grid[i][j] = 0;
                stack<pair<int, int>> s;
                s.push(pair{i, j});
                while (!s.empty()) {
                    auto [r, c] = s.top();
                    s.pop();
                    for (int k = 0; k < 4; ++k) {
                        auto x = r + direction[k];
                        auto y = c + direction[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < m &&
                            grid[x][y] == 1) {
                            local_area++;
                            grid[x][y] = 0;
                            s.push({x,y});
                        }
                    }
                }
                area = max(area, local_area);
            }
        }
    }
    return area;
}

int maxAreaOfIslandRecur(vector<vector<int>> grid) {
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v;
    v.push_back(vector{1,0,1,1,0,1,0,1});
    v.push_back(vector{1,0,1,1,0,1,1,1});
    v.push_back(vector{0,0,0,0,0,0,0,1});
    // v.push_back(vector{1,2,3,4});
    auto res = maxAreaOfIsland(v);
    printf("res = %d\n", res);
    return 0;
}
