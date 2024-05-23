// https://www.acwing.com/problem/content/787/

#include <iostream>

using namespace std;

static void quick_sort(int* arr, int left, int right) {
	if (left >= right) return;

	// 1. ���� X �ֽ��
	int x = arr[(left + right) >> 1];
	// ����˫ָ�룬��Ҫ�����ָһ��
	int i = left - 1;
	int j = right + 1;

	// 2. ��ʼ����
	// ȷ�� ��left <= x && ��right >= x
	while (i < j) {
		while (arr[++i] < x);
		while (arr[--j] > x);

		if (i < j) swap(arr[i], arr[j]);
	}

	// 3. �ݹ鴦����������
	quick_sort(arr, left, j);
	quick_sort(arr, j + 1, right);
}