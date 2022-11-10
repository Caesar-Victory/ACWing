#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 1331;
ULL h[N], p[N];
int n, m;
char str[N];

int main(void) {

	scanf("%d%d%s", &n, &m, 1 + str);

	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * P;
	}

	return 0;
}