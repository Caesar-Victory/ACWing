#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
// 分别为点数和边数
const int N = 510, M = 10010;

int n, m, k;
// 成对的数组，存储最短距离和备份最短距离
int dist[N], backup[N];

struct Edge {

    // 生成结构体，分别代表起点，终点和权重
    int a, b, w;

} edges[M];

// 重点逻辑：1, 如何处理负权【环】？2. 除法运算的原因
void bellman_ford(void) {

    // 对最短距离数组初始化，除1节点外，全部初始化为正无穷大
    // 避免负权回路的原因是备份在枚举每条边之前
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 经过边的个数是首要限制条件
    for (int i = 0; i < k; i++) {

        // 在进行每次拼接之前先备份上一次计算的数组
        memcpy(backup, dist, sizeof dist);

        for (int j = 0; j < m; j++) {

            // 分别提取三元组中的起点，终点和权重
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;

            // 计算最短距离，注意第二个参数中，除了权重应当使用备份数组，避免数据错乱
            // a, b是并行计算和修改的，这里没有看到拼接不同边长度的可能性
            dist[b] = min(dist[b], backup[a] + w);

        }

    }

}

int main(void) {

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++) {

        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a, b, w };

    }

    bellman_ford();
    // 最多500点，最多10000边，因此最大负值为500W，远远小于0x3f3f3f3f的一半
    // 最短路径的值域为 += 500W,远远小于21亿及其一半，因此这里除以2只是为了使得两者拟合
    if (dist[n] >= 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}
// 易错点：结构体名和别名以及结构体大小；计算最短距离拼接时使用备份数组；两层循环使用不同的变量作为指针
// https://www.acwing.com/video/285/
// https://www.acwing.com/activity/content/code/content/48523/