/*
 * @Date: 2021-10-09 20:48:22
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-09 20:50:28
 */
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin>>a>>b;
    int round = 12 * 60;
    int diff = round - a * 60 - b;
    cout<<(diff / 60) % 12 <<" "<< diff % 60<<endl;
    return 0;
}