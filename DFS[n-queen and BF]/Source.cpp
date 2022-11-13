#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int N = 20;
// 基本地图
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s) {
	// 此处有点精妙，当纵坐标耗尽之时，直接重置为0再来一遍
	if (y == n) y = 0, x++;
	if (x == n) {
		if (s == n) {
			for (int i = 0; i < n; i++) puts(g[i]);
			puts("");
		}
		return;
	}

	// 递归调用，该位置不放入皇后
	dfs(x, y + 1, s);

	// 欲放入皇后的点，满足行列，正反对角线没放皇后
	if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y]) {
		// 先放，修改四个方向的bool值
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
		dfs(x, y + 1, s + 1);
		// 搜索后重置状态，设置为False
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

	// 相当于启动器，设定搜索的起点和皇后的个数
	dfs(0, 0, 0);

	return 0;
}