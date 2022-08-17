#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e3 + 10;
// 新建时注意二维空间，变量名后面需要跟两个方括号和两个N
int a[N][N], s[N][N];
int n, m, q;

int main() {

	scanf("%d%d%d", &n, &m, &q);

	// 为防止溢出和遵循前缀和的计算，迭代均从1开始
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// 计算前缀和时，只有最后一项是a数组，也就是被累加的数组，其余三项均为同数组的递推
	// 递推时，从横坐标开始，需要交换-1；
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	while (q--) {
		int x1, y1, x2, y2;
		// 输入坐标时，遵循先小后大，先横坐标后纵坐标的原则
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		// 计算数组时，实际上我们需要的仅仅是正方形写斜对角那个方块的值
		// 因此先用总面积减去两个小长条的面积，然后追加小正方形面积
		printf("%d", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
	}

	return 0;
}