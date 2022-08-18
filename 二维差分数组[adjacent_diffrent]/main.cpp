#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int a[N][N], b[N][N];
int n, m, q;

void insert(int x1, int y1, int x2, int y2, int c) {
    // 先加最小的面积
    b[x1][y1] += c;
    // 将点向右移动
    b[x2 + 1][y1] -= c;
    // 将点向下移动
    b[x1][y2 + 1] -= c;
    // 补齐最小的正方形
    b[x2 + 1][y2 + 1] += c;
}

int main() {

    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            insert(i, j, i, j, a[i][j]);
        }
    }

    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 容易写错，此处为累加
            // 计算逻辑，顶端面积，等于两条小长方形面积减去小正方形面积
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        // 打印一层结束后再输出一个空格 用于分行
        for (int j = 1; j <= m; j++) {
            printf("%d ", b[i][j]);
        }
        puts(" ");
    }

    return 0;
}