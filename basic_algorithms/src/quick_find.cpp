// https://www.acwing.com/problem/content/788/

#include <iostream>

using namespace std;

static int quick_find(int*arr, int left, int right, int k) {
    if (left >= right) return arr[left];

    // 1. 定义 X 分界点
    int x = arr[(left + right) >> 1],
        i = left - 1,
        j = right + 1;

    // 2. 开始排序
    // 确保 数left <= x && 数right >= x
    while (i < j) {
        while (arr[++i] < x);
        while (arr[--j] > x);

        if (i < j) swap(arr[i], arr[j]);
    }

    // 3. 选择性递归
    int s_left = j - left + 1;
    // 第 k 个数在左集合，递归左边
    if (k <= s_left)
        return quick_find(arr, left, j, k);
    // 第 k 个数在右集合，递归右边
    else
        return quick_find(arr, j + 1, right, k - s_left);
}