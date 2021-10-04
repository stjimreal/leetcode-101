/*
 * @Date: 2021-09-22 13:11:36
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-09-22 13:50:42
 */
#include <iostream>
#include <vector>
#include <list>

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

void dfs(vector<pair<int, int>> &v, int i, int j) {
    if (map[i][j] == 1) return;
    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
        for_each(v.begin(), v.end(), [](pair<int, int> v){cout<<v.first<<" "<<v.second<<endl;});
        cout<<endl;
        return ;
    }
    for (int k = 0; k < 4; ++k) {
        v.push_back(pair{i, j});
        map[i][j] = 1;
        dfs(v, i + route[k], j + route[k + 1]);
        v.pop_back();
        map[i][j] = 0;
    }
}

int main(int argc, char const *argv[])
{
    vector<pair<int, int>> res;
    dfs(res, m / 2, n / 2);
    
    return 0;
}
