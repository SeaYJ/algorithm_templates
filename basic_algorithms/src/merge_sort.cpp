// https://www.acwing.com/problem/content/description/789/
#include <iostream>
using namespace std;

const int N = int(1e5);
int q[N], tmp[N];

static void merge_sort(int* arr, int left, int right) {
    if (left >= right) return;

    // 1. 确定索引中点
    int mid = (left + right) >> 1;

    // 2. 递归处理左右两边
    merge_sort(arr, left, mid), merge_sort(arr, mid + 1, right);

    // 3. 处理合并
    // 3.1 定义变量
    int k = 0,          // tmp 中已经排序的元素个数
        i = left,       // 第一个有序序列索引
        j = mid + 1;    // 第二个有序序列索引
    // 3.2 将两个有序序列合并到 tmp
    while (i <= mid && j <= right) {
        tmp[k++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
    }

    // 3.3 将可能剩余的元素合并到 tmp
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];

    // 3.4 将 tmp 还原到原数组
    for (i = left, j = 0; i <= right; i++, j++) {
        arr[i] = tmp[j];
    }
}