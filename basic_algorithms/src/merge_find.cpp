// https://www.acwing.com/problem/content/790/

#include <iostream>
using namespace std;

const int N = 1e5;
int arr[N], tmp[N];

static int merge_find(int left, int right)
{
	// �ݹ���ֹ����
	if (left >= right) return 0;

	// ȷ���ֽ��
	int mid = (right - left) / 2 + left;

	// �ݹ�
	// ��ͳ����ȫ�������������������������
	int count = merge_find(left, mid) + merge_find(mid + 1, right);

	// ȷ������
	int k = 0,
		i = left,
		j = mid + 1;

	// �鲢����
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i];
		}
		else {
			tmp[k++] = arr[j++];
			count += (mid - i + 1); // ͳ�ƣ���S[i] > S[j]���ң������������
		}
	}

	// ��β
	while (i <= mid) tmp[k++] = arr[i++];
	while (j <= right) tmp[k++] = arr[j++];

	// ����
	for (i = left, j = 0; i < right; i++, j++) {
		arr[i] = tmp[j];
	}

	// ����ͳ������
	return count;
}