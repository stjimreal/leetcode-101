/*
 * @Date: 2021-08-09 14:18:09
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-09 14:32:34
 */

#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <numeric>
#include <set>
#include <deque>
#include <queue>

using namespace std;

class Solution
{
private:
    
public:
    Solution();
    ~Solution();
    int nthSuperUglyNumber(int n, vector<int>& primes);
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::nthSuperUglyNumber(int n, vector<int>& primes) {
    priority_queue<int, vector<int>, greater<int> > ugly;
    set<int> traced_number;
    ugly.push(1);
    traced_number.insert(1);
    while (n--) {
        int x = ugly.top();
        ugly.pop();
        if (n == 0) return x;
        for (auto num: primes) {
            unsigned long mem = (unsigned long)num * x;
            if (mem > INT_MAX) {
                continue;
            }
            if (traced_number.find(mem) == traced_number.end()) {
                traced_number.insert(mem);
                ugly.push(mem);
            }
        }
    }
    return -1;

}

int main(int argc, char const *argv[])
{
    int n, k;
    cin>>n>>k;
    vector<int> primes;
    while(k--) {
        int num;
        cin>>num;
        primes.push_back(num);
    }
    auto res = Solution().nthSuperUglyNumber(n, primes);
    printf("%d\n", res);
    return 0;
}
