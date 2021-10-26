/*
 * @Date: 2021-10-16 20:10:09
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-16 20:16:12
 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int T;
    
    scanf("%d\n", &T);
    while (T--) {
        int N, M, res = 0;
        scanf("%d %d\n", &N, &M);
        unordered_map<char, pair<int, int>> keyboard;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                char now = getchar();
                if (now != '_') {
                    keyboard[now] = pair<int,int>{i,j};
                }
                // cout<<now;
            }
            // cout<<endl;
            getchar();
        }
        char ch;
        int x = 0, y = 0;
        while ((ch = getchar()) != EOF && ch != '\n') {
            res += abs(keyboard[ch].first-x) + abs(keyboard[ch].second-y) + 1;
            x = keyboard[ch].first;
            y = keyboard[ch].second;
        }
        cout<<res<<endl;
    }
    
    
}