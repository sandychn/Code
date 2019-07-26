/*
partial_sort(first, middle, last, comp) 部分排序
将元素重新排列，使得 [first, middle) 包含排好序的, [first, last) 区间中的 middle - first 个最小元素
相等元素的相对顺序可能被破坏
剩余在 [middle, last) 区间内的元素的顺序不做任何保证
复杂度 O((last - first) * log(middle - first))
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    partial_sort(v.begin(), v.begin() + 5, v.end());
    for (int val : v) cout << val << ' ';
    // Possible output: 1 2 3 4 5 9 8 7 6
    return 0;
}