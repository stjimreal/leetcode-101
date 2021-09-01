/*
 * @Date: 2021-08-06 19:04:32
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-06 21:23:20
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
private:
    
public:
    Solution();
    ~Solution();
};

Solution::Solution()
{
}

Solution::~Solution()
{
}
int main(int argc, char const *argv[])
{
    int row;
    scanf("%d\n", &row);
    vector<string> configText(row);
    for(int i = 0; i < row; ++i) {
        getline(cin, configText[i], '\n');
        cout<<configText[i]<<endl;
    }
    string query;
    getline(cin, query);

    
    return 0;
}
