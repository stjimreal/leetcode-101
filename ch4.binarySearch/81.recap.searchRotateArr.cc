/*
 * @Date: 2021-09-01 17:15:42
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-09-01 17:28:32
 */
#include <iostream>
#include <vector>

using namespace std;

int rotate(const int arr[], size_t n, int target) {
    size_t i = 0, j = n - 1;
    while (i <= j)
    {
        size_t mid = i + (j - i) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[i] == arr[mid] ) {
            ++i;
        } else {
            if (arr[i] < arr[mid]) {
                if (arr[i] <= target && target < arr[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else if (arr[mid] <= arr[j]) {
                if (arr[mid] < target && target <= arr[j]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {7,9,11,0,1,2,6};

    cout<<rotate(arr, 7, 11)<<endl;
    return 0;
}

