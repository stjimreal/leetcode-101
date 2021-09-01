/*
 * @Date: 2021-08-11 20:39:02
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-11 20:40:23
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    struct Comp {
        bool operator()(pair<int, int> v1, pair<int, int> v2) {
            return v1.second < v2.second;
        }
    };
    string frequencySort(string s) {
        string res;
        int alphablet[256] = {0};
        for (auto ch: s) {
            alphablet[ch]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> bucket;
        for(int i = 0; i < 256; ++i) {
            if (alphablet[i] > 0)
                bucket.push(pair(i, alphablet[i]));
        }
        int len = bucket.size();
        for (int i = 0; i < len; ++i) {
            auto memb = bucket.top();
            bucket.pop();
            res.append(memb.second, memb.first);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.frequencySort("Aabb");
    cout<<res<<endl;
    return 0;
}
