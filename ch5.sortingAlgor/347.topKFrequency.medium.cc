/*
 * @Date: 2021-08-11 20:05:46
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-11 20:09:56
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto num: nums) {
            map[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, Comp> freq_map;
        for (auto num: map) {
            freq_map.push(num);
        }
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = freq_map.top().first;
            freq_map.pop();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n, k;
    cin>>n>>k;
    vector<int> nums;
    while(n--) {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    Solution s;
    auto res = s.topKFrequent(nums, k);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
