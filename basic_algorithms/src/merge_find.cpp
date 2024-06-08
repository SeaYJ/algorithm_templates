// https://www.acwing.com/problem/content/790/

#include <iostream>
using namespace std;

const int N = 1e5;
int arr[N], tmp[N];

static int merge_find(int left, int right)
{
	// 递归终止条件
	if (left >= right) return 0;

	// 确定分界点
	int mid = (right - left) / 2 + left;

	// 递归
	// 并统计完全在左区间和右区间的逆序对数量
	int count = merge_find(left, mid) + merge_find(mid + 1, right);

	// 确定索引
	int k = 0,
		i = left,
		j = mid + 1;

	// 归并排序
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i];
		}
		else {
			tmp[k++] = arr[j++];
			count += (mid - i + 1); // 统计（左）S[i] > S[j]（右）的逆序对数量
		}
	}

	// 收尾
	while (i <= mid) tmp[k++] = arr[i++];
	while (j <= right) tmp[k++] = arr[j++];

	// 更新
	for (i = left, j = 0; i < right; i++, j++) {
		arr[i] = tmp[j];
	}

	// 返回统计数量
	return count;
}