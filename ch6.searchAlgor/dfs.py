'''
Date: 2021-10-04 10:29:14
LastEditors: LIULIJING
LastEditTime: 2021-10-04 10:57:52
'''
from typing import List


map = [
    [1,1,1,1,1,1,1,0,1,1,1],
    [1,0,0,1,0,1,1,1,0,1,0],
    [0,0,1,0,0,0,0,0,1,0,0],
    [1,0,0,1,0,0,1,0,0,1,1],
    [1,1,0,0,1,0,0,0,0,0,1],
    [0,1,0,1,1,1,0,1,0,1,0],
    [0,0,1,1,1,0,1,0,0,1,1],
    [0,1,0,1,0,0,1,1,0,0,1],
    [1,1,0,0,1,0,1,1,1,0,1],
]
m = len(map)
n = len(map[0])

def dfs(v: List[List[int]], i, j) -> bool:
    if i < 0 or i >= m or j < 0 or j >= n:
        return True
    if v[i][j] == 0:
        v[i][j] = 1
        if dfs(v, i - 1, j) or dfs(v, i + 1, j) or \
            dfs(v, i, j - 1) or dfs(v, i, j + 1):
            print(i, j)
            v[i][j] = 0
            return True
        else:
            v[i][j] = 0
            return False
    else:
        return False

res = []
def bfs(v: List[List[int]], i, j):
    if i < 0 or i >= m or j < 0 or j >= n:
        return
    if v[i][j] == 1:
        return
    else:
        q = []
        q.append((i, j))
        while len(q) > 0:
            x, y = q.pop(0)
            if x < 0 or x >= m or y < 0 or y >= n:
                print(res)
                break
            if v[x][y] == 1:
                pass
            else:
                res.append((x, y))
                v[x][y] = 1
                q.append((x - 1, y))
                q.append((x, y - 1))
                q.append((x + 1, y))
                q.append((x, y + 1))

if __name__ == "__main__":
    dfs(map, int(m/2), int(n/2))
    bfs(map, int(m/2), int(n/2))
    