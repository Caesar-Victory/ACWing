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
    // 分别对应队头与队尾
    int hh = 0, tt = 0;
    q[0] = { 0, 0 };
    // 将表示距离的矩阵全部初始化为-1
    memset(d, -1, sizeof d);
    d[0][0] = 0;

    // 四个方向 向下，向上，向右，向左，保证横纵坐标对应即可
    int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

    // 队列不为空罢了 【队头指针不会递减到队尾】
    while (hh <= tt) {

        auto t = q[hh++];

        for (int i = 0; i < 4; i++) {

            // 计算坐标，对二元组坐标分别计算，之前我是用vector插入的，效率或许更高一些 
            int x = t.first + dx[i], y = t.second + dy[i];
            // 三组条件，分别是 横纵坐标不能越界，该坐标值为0，该坐标的距离为-1【未被访问过】   
            if ((x >= 0 && x < n) && (y >= 0 && y < m) && g[x][y] == 0 && d[x][y] == -1) {
                // 类似于动态规划和前缀和，状态累加
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

     