#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void count_primes(int n) {

	// 搜索所有的数
	for (int i = 2; i <= n; i++) {
		// 找到质数
		if (!st[i]) primes[cnt++] = n;
		// 标记法删除该质数的所有倍数
		for (int j = i * 2; j <= n; j += i) st[j] = true;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	count_primes(n);
	printf("%d\n", cnt);
	return 0;
}

// 难点：理解倍数筛选的原理
// 易错点：判断条件用双等号，赋值用单等号；内外层循环均能遍历到上限
// https://www.acwing.com/video/293/
// https://www.acwing.com/activity/content/code/content/49975/