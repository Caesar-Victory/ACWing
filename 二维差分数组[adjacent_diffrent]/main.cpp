#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int a[N][N], b[N][N];
int n, m, q;

// 洪泛计算【核心区域(x1, y1)开始整个小正方形 - 第一第四象限面积 - 第三第四象限面积 + 第四象限面积】
// 可类比 DFS 搜索核心点周围四个坐标 (x + 1, y) (x, y + 1) (x, y), (x + 1, y + 1)
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

//所有数组的读入和写出都在 [1, n]的范围内，二维坐标需两个方括号
// 步骤 1. 键盘输入读入数组 a[N][N]; 2, 插入差分数组 b[N][N]; 
// 3, 读取输入并且在指定区间内插入; 
// 4, 计算前缀和 当前下标 = 横纵坐标各退一个单位【第一第四】 - 横纵坐标同时退一个单位【第四象限】
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
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", b[i][j]);
        }
        puts(" ");
    }

    return 0;
}