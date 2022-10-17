#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], temp[N];

void merge_sort(int q[], int l, int r) {
	// 判断边界,递归的终止条件
	if (l >= r) {
		return;
	}

	// 生成中点，左右虚拟指针，以及值为零的指针[便于移动临时数组]
	int mid = (l + r) >> 1, j = l, k = mid + 1, c = 0;

	// 先递归排序左右区间的值
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

	// 循环迭代，条件分别为左右区间，设置为 && 语句是为了左右任何一个区间排序未结束退出
	while (j <= mid && k <= r) {
		//直接比较数值左右虚拟指针对应的数值 小于关系存小的
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

	// 只能将copy的左右指针定界为 [l, r] 不能是如何实值
	// 需要两个指针进行移动，便于copy数值
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