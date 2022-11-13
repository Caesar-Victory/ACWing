#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e2 + 10;
int n, m;
int g[N][N], d[N][N];
PII q[N * N];

int bfs(void) {
    // �ֱ��Ӧ��ͷ���β
    int hh = 0, tt = 0;
    q[0] = { 0, 0 };
    // ����ʾ����ľ���ȫ����ʼ��Ϊ-1
    memset(d, -1, sizeof d);
    d[0][0] = 0;

    // �ĸ����� ���£����ϣ����ң����󣬱�֤���������Ӧ����
    int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

    // ���в�Ϊ�հ��� ����ͷָ�벻��ݼ�����β��
    while (hh <= tt) {

        auto t = q[hh++];

        for (int i = 0; i < 4; i++) {

            // �������꣬�Զ�Ԫ������ֱ���㣬֮ǰ������vector����ģ�Ч�ʻ������һЩ 
            int x = t.first + dx[i], y = t.second + dy[i];
            // �����������ֱ��� �������겻��Խ�磬������ֵΪ0��������ľ���Ϊ-1��δ�����ʹ���   
            if ((x >= 0 && x < n) && (y >= 0 && y < m) && g[x][y] == 0 && d[x][y] == -1) {
                // �����ڶ�̬�滮��ǰ׺�ͣ�״̬�ۼ�
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = { x, y };
            }
        }
    }

    return d[n - 1][m - 1];
}

int main(void) {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> g[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}

     