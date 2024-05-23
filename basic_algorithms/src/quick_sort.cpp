// https://www.acwing.com/problem/content/787/

#include <iostream>

using namespace std;

static void quick_sort(int* arr, int left, int right) {
	if (left >= right) return;

	// 1. 定义 X 分界点
	int x = arr[(left + right) >> 1];
	// 定义双指针，需要向外多指一层
	int i = left - 1;
	int j = right + 1;

	// 2. 开始排序
	// 确保 数left <= x && 数right >= x
	while (i < j) {
		while (arr[++i] < x);
		while (arr[--j] > x);

		if (i < j) swap(arr[i], arr[j]);
	}

	// 3. 递归处理左右两边
	quick_sort(arr, left, j);
	quick_sort(arr, j + 1, right);
}