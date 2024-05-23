// https://www.acwing.com/problem/content/description/789/
#include <iostream>
using namespace std;

const int N = int(1e5);
int q[N], tmp[N];

static void merge_sort(int* arr, int left, int right) {
    if (left >= right) return;

    // 1. ȷ�������е�
    int mid = (left + right) >> 1;

    // 2. �ݹ鴦����������
    merge_sort(arr, left, mid), merge_sort(arr, mid + 1, right);

    // 3. ����ϲ�
    // 3.1 �������
    int k = 0,          // tmp ���Ѿ������Ԫ�ظ���
        i = left,       // ��һ��������������
        j = mid + 1;    // �ڶ���������������
    // 3.2 �������������кϲ��� tmp
    while (i <= mid && j <= right) {
        tmp[k++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
    }

    // 3.3 ������ʣ���Ԫ�غϲ��� tmp
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];

    // 3.4 �� tmp ��ԭ��ԭ����
    for (i = left, j = 0; i <= right; i++, j++) {
        arr[i] = tmp[j];
    }
}