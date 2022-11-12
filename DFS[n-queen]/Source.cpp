#include <cstdio>
#include <iostream>

using namespace std;
int n;
const int N = 20;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
	// 出口，控制搜索完所有行列之后的输出
	if (u == n) {
		for (int i = 0; i < n; i++) puts(g[i]);
		puts("");
	}

	// 整体采用bool标记，同时标记每一列，正反对角线
	for (int i = 0; i < n; i++) {
		// 三者均没有放置皇后才能试着放置
		if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
			// 搜索前后注意状态的变更，搜索前将其置为皇后，搜索后复原
			g[u][i] = 'Q';
			// 对角线坐标计算来源于第一第二象限截距
			col[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = false;
			g[u][i] = '.';
		}
	}
}

int main(void) {

	cin >> n;

	// 可以立即为对地图绘制基本色
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			g[i][j] = '.';
		}
	}

	dfs(0);
	return 0;
}