/*
 * @Date: 2021-08-09 20:50:28
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-10 10:41:38
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <random>

using namespace std;

template <typename T, typename Compare=std::less<T>>
void insert_sort(vector<T> &v) {
    Compare comp;
    for (size_t i = 1; i < v.size(); ++i)
    {
        auto elem = v[i];
        size_t j = i;
        for (;j > 0; --j) {
            if (comp(v[j - 1], elem)) break;
            v[j] = v[j - 1];
        }
        v[j] = elem;
    }
}

template <typename T, typename Compare=std::less<T>>
void bubble_sort(vector<T> &v) {
    Compare comp;
    for (size_t i = 0; i < v.size(); ++i)
    {
        for (size_t j = v.size() - 1; j > 0; --j) {
            if (comp(v[j], v[j - 1])) swap(v[j], v[j - 1]);
        }
    }
}

template <typename T, typename Compare=std::less<T>>
void shell_sort(vector<T> &v) {
    Compare comp;
    size_t len = v.size();
    for (size_t step = len / 2; step > 0; --step) {
        for (size_t i = step; i < len; ++i) {
            T elem = v[i];
            size_t j = i;
            for (; j > 0; j -= step) {
                if (comp(v[j - step], elem)) break;
                v[j] = v[j - step];
            }
            v[j] = elem;
        }
    }
}

template <typename T, typename Compare=std::less<T>>
void select_sort(vector<T> &v) {
    Compare comp;
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (comp(v[j], v[i])) swap(v[i], v[j]);
        }
    }
}

template <typename T, typename Compare>
size_t partition(vector<T> &v, size_t beg, size_t end)
{
    Compare comp;
    int i = beg, j = end - 1;
    T partition = v[i];
    while (i < j) {
        while (i < j && !comp(v[j], partition)) --j;
        v[i] = v[j];
        while (i < j && !comp(partition, v[i])) ++i;
        v[j] = v[i];
    }
    v[i] = partition;
    return i;
}


template <typename T, typename Compare=std::less<T>>
void quick_sort_impl(vector<T> &v, size_t beg, size_t end)
{
    if (beg >= end) return;
    size_t parti = partition<T, Compare>(v, beg, end);
    quick_sort_impl(v, beg, parti);
    quick_sort_impl(v, parti + 1, end);
}

template <typename T, typename Compare=std::less<T>>
void quick_sort(vector<T> &v) {
    quick_sort_impl<T, Compare>(v, 0, v.size());
}

template <typename T, typename Compare>
void heapify(vector<T> &v, size_t beg, size_t end)
{
    size_t son = beg * 2 + 1;
    Compare comp;
    while (son < end) {
        if (son + 1 < end && comp(v[son + 1], v[son])) {
            son++;
        }
        if (comp(v[son], v[beg])) 
        {
            swap(v[son], v[beg]);
            beg = son;
            son = beg * 2 + 1;
        } else {
            break;
        }
    }
}

template <typename T, typename Compare=std::greater<T>>
void heap_sort(vector<T> &v) {
    for (size_t i = v.size() / 2; i > 0; --i) {
        heapify<T, Compare>(v, i - 1, v.size());
    }
    for (size_t i = v.size() - 1; i > 0; --i) {
        swap(v[0], v[i]);
        heapify<T, Compare>(v, 0, i);
    }
}

template <typename T, typename Compare=std::less<T>>
void merge_now(vector<T> &v1, vector<T> &v2, size_t l, size_t r, size_t mid)
{
    Compare comp;
    size_t beg1 = l, beg2 = mid;
    while(beg1 < mid || beg2 < r) {
        if (beg1 < mid && beg2 < r) {
            v2[l++] = comp(v1[beg1], v1[beg2])? v1[beg1++]: v1[beg2++];
        } else {
            if (beg2 >= r) {
                v2[l++] = v1[beg1++];
            } else if (beg1 >= mid){
                v2[l++] = v1[beg2++];
            }
        }        
    }
}

template <typename T, typename Compare=std::less<T>>
void merge_sort(vector<T> &v) {
    vector<T> avator(v);
    size_t len = v.size();
    for (size_t step = 1; step < len;step *= 2)
    {
        for (size_t beg = 0; beg < len; beg += step * 2) {
            size_t end = beg + step * 2 > len? len: beg + step * 2;
            size_t mid = beg + step;
            merge_now<T, Compare>(v, avator, beg, end, mid);
        }
        swap(avator, v);
    }
}


int main(int argc, char const *argv[])
{
    int k;
    vector<int> v;
    cin>>k;
    while(k--) {
        int num;
        cin>>num;
        v.push_back(num);
    }
    merge_sort(v);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}
