#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], s[N];
int n, m;

int main() {

	// 分别获取数组的长度，和查询的次数
	scanf("%d%d", &n, &m);

	// 将输入的数值读入数组
	for (int i = 1; i <= n; i++) scanf("%d", &q[i]);

	// 注意累加的方法，是当前数组的上一个位序对应的值，加上累加对象的当前位序
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + q[i];

	while (m--) {

		int l, r;
		scanf("%d%d", &l, &r);
		// 减一是因为读入和累加均从1开始[避免索引越界]
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}