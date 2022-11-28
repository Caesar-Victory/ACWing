#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int h[N], e[N], nxt[N], w[N], idx;
// 设置为全局变量，等价于设定默认值0，其实设置为任何值都可以
// 使用memset()可以将其设置为0x3f, 0x7f, 127,128
// 也可以理解为超级源点，它与每一个节点连接，作为每一个节点的前驱，但权重为0，所以原图的负权回路等于连接后的新图的负权回路
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {

    e[idx] = b; w[idx] = c, nxt[idx] = h[a], h[a] = idx++;
}

// 负环指的是路径和为负数，而非环的权重包含负数
// 难点在于对dist[n]的理解
bool spfa(void) {
    // 可以替换为stack, 快500倍
    queue<int> q;
    // 全部节点插入队列，可以解决不连通的问题
    for (int i = 1; i <= n; i++) {

        q.push(i);
        st[i] = true;
    }

    while (q.size()) {

        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = nxt[i]) {

            int j = e[i];

            // 判断负权的方式是；更新比0更小的距离，等价于只更新负权
            if (dist[j] > dist[t] + w[i]) {

                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                // 如果累计节点数超过n说明一个点被用两次肯定存在环
                // 可以用m边数判断，但n的数据集显著小于m，所以会更快更优
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main(void) {

    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if (spfa()) puts("Yes");
    else puts("No");

    // 输出 dist[]是为了查看每一个节点的最短路径，发现其均为0，说明只更新负权距离，测试样例均为正值
    // for (int i = 1; i <= n; i++) printf("%d\n", dist[i]);

    return 0;
}

// TR算法，可以作为图论的补充知识
// https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm
// https://oi-wiki.org/graph/scc/