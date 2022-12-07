#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

// 无向图开两倍的存储空间
const int N = 1e5 + 10, M = 2 * 1e5 + 10;

using namespace std;

int n, m;
int h[N], e[M], nxt[M], idx;
int color[N];

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {

    // 记录当前点的颜色
    color[u] = c;
    // 遍历一下当前点的所有邻点
    for (int i = h[u]; i != -1; i = nxt[i]) {

        // 用 j 存储当前点的编号
        int j = e[i];
        // 还未染色，默认为0，既不是1，也不是2
        if (!color[j]) {
            // 3 - c就可以实现 1 ---> 2 / 2 ---> 1
            // DFS逐层深入，在已知上层颜色为c的情况下，把下层通过3-c转换即可
            // 3- c 用来转换颜色，在一个只有1，2两种颜色的图中，可以达到一种非此即彼的效果
            if (!dfs(j, 3 - c)) return false;
            // 父子同色则返回False
        }
        // 和红黑树的定义近似，一个红色节点必有两个黑色的子节点；换句话说，父子节点的颜色不一样
        // 可用于处理自环，自环的定义是自己指向自己，那么必然导致起点和终点的颜色相同
        else if (color[j] == c) return false;
    }

    return true;
}

int main(void) {

    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m--) {

        int a, b;
        scanf("%d%d", &a, &b);
        // 邻接表存储无向图则是存储两次
        // 邻接矩阵存储图则是交换坐标存储两次，例如 g[a][b] = g[b][a] = min(g[a][b], c)
        add(a, b), add(b, a);
    }

    // 标记染色过程中的矛盾
    bool flag = true;

    // 按照节点开始染色；遍历所有节点是防止有的点之间不连通
    for (int i = 1; i <= n; i++) {

        // 当前点没有被染色
        if (!color[i]) {

            // 返回值为False 有矛盾发生，立即停止染色
            // 也可以理解为第一层颜色为1
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }

    if (flag) puts("Yes");
    else puts("No");

    return 0;
}

// https://www.acwing.com/video/289/
// https://www.acwing.com/activity/content/code/content/48778/