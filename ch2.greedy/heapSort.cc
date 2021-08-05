/*
 * @Date: 2021-07-13 16:41:19
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-13 16:57:59
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T, typename Compare>
void heapify(vector<T> &v, int beg, int end){
  Compare comp;
  int son = beg * 2 + 1;
  while (son < end && beg < end) {
    if (son + 1 < end && comp(v[son + 1], v[son])) {
      son++;
    }
    if (comp(v[beg], v[son])) {
      return;
    } else {
      swap(v[beg], v[son]);
      // heapify(v, son, end);
      beg = son;
      son = beg * 2 + 1;
    }
  }
}

template<typename T, typename Compare>
void heap_sort(vector<T> &v) {
  size_t len = v.size();
  size_t last_leaf = len / 2;
  for (int i = last_leaf; i > 0; --i) {
    heapify<T, Compare>(v, i - 1, len);
  }
  for (int i = len; i > 0; --i) {
    swap(v[0], v[i - 1]);
    heapify<T, Compare>(v, 0, i - 1);
  }
}

int main()
{
  vector<int> v{1, 3, 4, 2, -1, 7, 0, 3, 9, -4, 8,0};
  heap_sort<int, std::greater<int>>(v);
  std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
  cout<<endl;
}