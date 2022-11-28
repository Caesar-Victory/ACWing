#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

// Q指的是查询次数
int n, m, Q;
// 邻接矩阵存储图
int d[N][N];


void floyd(void) {
    // K在这里的意思，刚好是一个截断点，也是一种状态
    // 具体来说，k指的是在路径 i - j 中抛去 k 节点的所有距离
    // 因此动态规划实际上是一个三维，
    // 转移方程为 dist(i, j, k) = min(dist(im j, k-1), dist(i, k, k-1) + dist(k, j, k-1))
    for (int k = 1; k <= n; k++) {
        // 第二，第三重循环分别枚举起点和终点
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {

                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

}

// 重边只需要保留长度最小的边即可，自环直接删去
int main(void) {

    scanf("%d%d%d", &n, &m, &Q);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            // 指向自己的距离默认为0，其余默认为正无穷
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    while (m--) {

        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);

        // 重边指的是对同一组起点和终点，提交不同的权重
        // 滑动数组只保留距离最短的那个权重
        d[a][b] = min(d[a][b], w);

    }

    floyd();

    while (Q--) {

        int a, b;
        scanf("%d%d", &a, &b);
        // 找一个不太大的值作为参考系，避免最大值的宽容度太大，将较大的最短距离也当作找不到最短距离处理
        if (d[a][b] > INF / 2) puts("impossible");
        else printf("%d\n", d[a][b]);

    }

    return 0;
}
// https://www.acwing.com/activity/content/code/content/48531/
// https://www.acwing.com/video/286/