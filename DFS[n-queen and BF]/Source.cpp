#include <iostream>
#include <cstdio>

using namespace std;

int n;
const int N = 20;
// ������ͼ
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s) {
	// �˴��е㾫���������ľ�֮ʱ��ֱ������Ϊ0����һ��
	if (y == n) y = 0, x++;
	if (x == n) {
		if (s == n) {
			for (int i = 0; i < n; i++) puts(g[i]);
			puts("");
		}
		return;
	}

	// �ݹ���ã���λ�ò�����ʺ�
	dfs(x, y + 1, s);

	// ������ʺ�ĵ㣬�������У������Խ���û�Żʺ�
	if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y]) {
		// �ȷţ��޸��ĸ������boolֵ
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
		dfs(x, y + 1, s + 1);
		// ����������״̬������ΪFalse
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

	// �൱�����������趨���������ͻʺ�ĸ���
	dfs(0, 0, 0);

	return 0;
}