/*
 * @Date: 2021-08-10 15:04:53
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-10 15:05:52
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        /* 折半查找 */
        int res = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            auto mid = l + (r - l) / 2;
            if (citations[mid] > n) {
                r = mid - 1;
                continue; /* 0 1 2 3 4  ->5 */
            } else if (citations[mid] == n - mid) {
                res = citations[mid];
                break;
            } else if (citations[mid] < n - mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }       
};

int main() {
    Solution s;
    return 0;
}