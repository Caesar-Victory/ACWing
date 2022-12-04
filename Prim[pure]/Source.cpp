#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// 看节点与边比例--->知稠密图
const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim(void) {

    // 先把所有距离初始化为正无穷
    memset(dist, 0x3f, sizeof dist);

    // 最小生成树里面，所有边的长度之和
    int res = 0;

    // 每一次遍历找到当前集合外，距离最短的点
    // 每一次迭代求最短路径时，已经计算了最短路径总长度，因此遍历 n 次，而不是 n - 1次
    for (int i = 0; i < n; i++) {

        int t = -1;

        for (int j = 1; j <= n; j++)
            // 集合外，没找到任何一个点 | t 的距离大于 j 的距离
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                // t 存储当前距离最小的点
                t = j;


        // 不是第一个点，并且距离等于正无穷；说明离当前集合距离最近的点，均为正无穷
        // 图不连通，不存在最小生成树
        if (i && dist[t] == INF) return INF;
        // 只要不是第一条边，我们就将距离累加到集合当中去
        if (i) res += dist[t];
        // Prim 算法中 dist[t] 表示 点 t 到集合的距离
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
        // 加入到集合当中，则将其标记为true
        st[t] = true;
    }
    return res;
}

int main(void) {

    scanf("%d%d", &n, &m);

    // 赋予初值需要遍历矩阵，至少为双重循环，此写法效率更高
    memset(g, 0x3f, sizeof g);

    while (m--) {

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);

    }

    int t = prim();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}