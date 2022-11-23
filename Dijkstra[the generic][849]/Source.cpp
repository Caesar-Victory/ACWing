#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
// 500个点,10W个边，稠密图，用邻接矩阵来存储图
// 邻接矩阵就是一个矩阵，是什么，取决于使用该结构去实现什么功能
int g[N][N];
// Dikjkstra算法中的距离，表达的是从1号点走到2……n号点的距离是多少
int dist[N];
// 表示当前点的最短路是否已经确定,相当于集合S
bool st[N];

int dijkstra() {
    // st[1] = true;
    // 第一步：初始化距离
    memset(dist, 0x3f, sizeof dist);
    // 起点与自身相差0单位长度的距离
    dist[1] = 0;
    // 遍历次数只和需要修改的点的个数有关，这里并不是因为节点1的距离等于0已经被更新
    // 这里可以理解为接龙，前 n - 1个点全部都是当前最短路径，那么 n 节点 1- n 必为最短距离
    // 而是因为 n - 1个点更新时，n的最短距离也更新了，换句话说更新 n - 1个点是因为最后一个点无需更新
    // 和第一个点没有关系；除此之外可以利用反证法，直接在第一层循环外面，令 s[1] = true
    for (int i = 0; i < n; i++) {
        // 为什么赋值为-1呢？ 表示还没有确定最短距离;不在S集合中，离1距离最近的点
        int t = -1;
        // 遍历每一个节点
        for (int j = 1; j <= n; j++) {
            // 这个点没有确定最短距离 或者说当前点的距离不是最短的
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        // 用 t 来更新其他点的距离
        for (int j = 1; j <= n; j++) {
            // 松弛操作，距离累加，此处的 t 相当于两根水管的耦合节点
            // 一节距离 对 一组距离不等的节 使用滑动数组更新最短路径，也可以理解为复杂度为n的试除法
            // 优先队列也是最小值的方法之一
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        }

        // 逻辑意义：对于已经找到最短路径的节点，将其标记为true
        // 特别容易忘记，记住这里面只有变量 t 是与 st[]数组同级别全局变量，其余均在各自的循环当中
        st[t] = true;

    }
    // d[v]中存储的便是从s到v的最短路径，或者如果路径不存在的话是无穷大
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(void) {
    // 读入点数和边数
    scanf("%d%d", &n, &m);
    // 如果自环中，所有边权是正的，那么自环显然不会出现在最短路里面；
    // 重边的话，只用保留节点之间距离最短的边就可以了

    // 初始化，0x3f 可以看作INT类型的上限，但具有伸缩性
    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        // 参数C指的是边长，计算出的最短路径可以小于边长
        // a 和 b 之间可能有多条边【重边】，我们保留长度最短的那条边就可以了
        // 邻接矩阵也是起点和终点的双向绑定，因为距离为正权，即使位序颠倒【起点和终点对换】，两者间距离唯一
        g[a][b] = min(g[a][b], c);
    }

    int t = dijkstra();

    printf("%d\n", t);


    return 0;
}
// https://www.acwing.com/activity/content/code/content/48488/
// https://www.acwing.com/video/281/