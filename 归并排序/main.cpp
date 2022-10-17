#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], temp[N];

void merge_sort(int q[], int l, int r) {
	// �жϱ߽�,�ݹ����ֹ����
	if (l >= r) {
		return;
	}

	// �����е㣬��������ָ�룬�Լ�ֵΪ���ָ��[�����ƶ���ʱ����]
	int mid = (l + r) >> 1, j = l, k = mid + 1, c = 0;

	// �ȵݹ��������������ֵ
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

	// ѭ�������������ֱ�Ϊ�������䣬����Ϊ && �����Ϊ�������κ�һ����������δ�����˳�
	while (j <= mid && k <= r) {
		//ֱ�ӱȽ���ֵ��������ָ���Ӧ����ֵ С�ڹ�ϵ��С��
		if (q[j] <= q[k]) {
			temp[c++] = q[j++];
		}
		else {
			temp[c++] = q[k++];
		}
	}

	while (j <= mid) {
		temp[c++] = q[j++];
	}

	while (k <= r) {
		temp[c++] = q[k++];
	}

	// ֻ�ܽ�copy������ָ�붨��Ϊ [l, r] ���������ʵֵ
	// ��Ҫ����ָ������ƶ�������copy��ֵ
	for (int i = l, m = 0; i <= r; i++, m++) {
		q[i] = temp[m];
	}
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
	}

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d", q[i]);
	}

	return 0;
}