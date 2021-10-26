/*
 * @Date: 2021-10-13 19:12:00
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-13 19:17:05
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
class Solution {
public:
    /* Write Code Here */
    vector < int > mergeSortedArray(vector < int > &a, int m, vector < int > &b, int n) {
        int i = a.size() - n - 1, j = n - 1;
        int k = a.size() - 1;
        while (i >= 0 && j >= 0) {
            a[k--] = a[i] > b[j] ? a[i--]: b[j--];
        }
        while (j>=0) {
            a[k--] = b[j--];
        }
        return a;
    }
};
int main() {
    vector < int > res;

    int _a_size = 0;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _a.push_back(_a_item);
    }


    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _b_size = 0;
    cin >> _b_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _b;
    int _b_item;
    for(int _b_i=0; _b_i<_b_size; _b_i++) {
        cin >> _b_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _b.push_back(_b_item);
    }


    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    
    Solution *s = new Solution();
    res = s->mergeSortedArray(_a, _m, _b, _n);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;

}
