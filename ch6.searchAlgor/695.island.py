'''
Date: 2021-10-04 10:05:01
LastEditors: LIULIJING
LastEditTime: 2021-10-04 10:28:43
'''

from typing import List


def maxAreaOfIsland(grid: List[List[int]]):
    m = len(grid)
    n = len(grid[0])
    area = 0
    res = 0
    def recur_search(i, j) -> bool:
        if i < 0 or i >= m or j < 0 or j >= n:
            return False
        if grid[i][j] == 1:
            grid[i][j] = 0
            x1 = recur_search(i - 1, j)
            y1 = recur_search(i, j - 1)
            x2 = recur_search(i + 1,j)
            y2 = recur_search(i, j + 1)
            return x1 or y1 or \
                    x2 or y2 or True
        else:
            return False
    for i in range(m):
        for j in range(n):
            if recur_search(i, j):
                res += 1
    print(res)
    return res

if __name__ == '__main__':
    grid = [[0,1,0,0,0,1,1],
            [1,1,0,1,0,1,0],
            [0,1,1,1,0,0,1],
            [1,0,0,1,0,1,1],
            [1,1,0,0,1,1,0]]
    maxAreaOfIsland(grid)
