#include <cstdio>
#include <iostream>

using namespace std;
int n;
const int N = 20;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
	// ���ڣ�������������������֮������
	if (u == n) {
		for (int i = 0; i < n; i++) puts(g[i]);
		puts("");
	}

	// �������bool��ǣ�ͬʱ���ÿһ�У������Խ���
	for (int i = 0; i < n; i++) {
		// ���߾�û�з��ûʺ�������ŷ���
		if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
			// ����ǰ��ע��״̬�ı��������ǰ������Ϊ�ʺ�������ԭ
			g[u][i] = 'Q';
			// �Խ������������Դ�ڵ�һ�ڶ����޽ؾ�
			col[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = false;
			g[u][i] = '.';
		}
	}
}

int main(void) {

	cin >> n;

	// ��������Ϊ�Ե�ͼ���ƻ���ɫ
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			g[i][j] = '.';
		}
	}

	dfs(0);
	return 0;
}