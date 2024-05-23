// https://www.acwing.com/problem/content/788/

#include <iostream>

using namespace std;

static int quick_find(int*arr, int left, int right, int k) {
    if (left >= right) return arr[left];

    // 1. ���� X �ֽ��
    int x = arr[(left + right) >> 1],
        i = left - 1,
        j = right + 1;

    // 2. ��ʼ����
    // ȷ�� ��left <= x && ��right >= x
    while (i < j) {
        while (arr[++i] < x);
        while (arr[--j] > x);

        if (i < j) swap(arr[i], arr[j]);
    }

    // 3. ѡ���Եݹ�
    int s_left = j - left + 1;
    // �� k �������󼯺ϣ��ݹ����
    if (k <= s_left)
        return quick_find(arr, left, j, k);
    // �� k �������Ҽ��ϣ��ݹ��ұ�
    else
        return quick_find(arr, j + 1, right, k - s_left);
}