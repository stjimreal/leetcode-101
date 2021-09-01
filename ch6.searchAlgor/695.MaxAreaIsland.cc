/*
 * @Date: 2021-09-01 17:29:35
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-09-01 17:37:31
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

/* 

    [
        [1,0,1,1,0,1,0,1],
        [1,0,1,1,0,1,1,1],
        [0,0,0,0,0,0,0,1],
    ]

 */
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int direction[] = {-1, 0, 1, 0, -1};
    
}