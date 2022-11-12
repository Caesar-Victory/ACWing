#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int N = 20;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s) {
	if (y == n) y = 0, x++;
	if (x == n) {
		if (s == n) {
			for (int i = 0; i < n; i++) puts(g[i]);
			puts("");
		}
		return;
	}

	dfs(x, y + 1, s);

	if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y]) {
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
		dfs(x, y + 1, s + 1);
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
		g[x][y] = '.';
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {

			g[i][j] = '.';
		}
	}

	dfs(0, 0, 0);

	return 0;
}