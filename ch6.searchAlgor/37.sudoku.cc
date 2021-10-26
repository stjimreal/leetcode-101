/*
 * @Date: 2021-10-10 16:50:23
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-10 18:01:33
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // cout<<cnt<<endl;
        int m = board.size(), n = m;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    stack<pair<int, int>> q;
                    stack<pair<char, pair<int, int>>> cache;
                    q.push(pair{i, j});
                    cache.push(pair{'.', pair{i, j}});
                    while (!q.empty()) {
                        auto [i, j] = q.top();
                        auto [ch, p] = cache.top();
                        auto [pre_i, pre_j] = p;
                        board[pre_i][pre_j] = ch;
                        bool vault = true;
                        q.pop();
                        cache.pop();

                        int map[256] = {0};
                        int ibeg = i / 3;
                        int jbeg = j / 3;
                        vector<pair<int, int>> son;
                        for (int x = ibeg; x < ibeg + 3; ++x) {
                            for (int y = jbeg; y < jbeg + 3; ++y) {
                                if (board[x][y] == '.') {
                                    son.push_back(pair{x, y});
                                } else {
                                    map[board[x][y]] = 1;
                                }
                               
                            }
                        }
                        for (int k = 0; k < 9; ++k) {
                            if (board[i][k] == '.') {
                                son.push_back(pair{i, k});
                            }
                            if (board[k][j] == '.') {
                                son.push_back(pair{k, j});
                            }
                            map[board[i][k]] = 1;
                            map[board[k][j]] = 1;
                        }
                        for (char k = '1'; k <= '9'; ++k) {
                            if (map[k] == 0) {
                                vault = false;
                                for (int t = 0; t < son.size(); ++t) {
                                    q.push(son[t]);
                                    cache.push(pair{k, pair{i, j}});
                                }
                            }
                        }

                        /* 尝试出错了，开始回溯 */
                        if (vault) {
                            board[pre_i][pre_j] = '.';
                        }
                    }
                    
                }
            }
        }
        // cout<<"here"<<endl;
        // flag = true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>>matrix={{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(matrix);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
