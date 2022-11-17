#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

// 因为是无向图，存储时为双向存储，无论是保存值的 e[] 数组还是保存nxt指针的 nxt[]数组都需要开辟二倍的空间
const int N = 1e5 + 10, M = N * 2;

// 存储的是最小的最大值
int n;
int ans = N;
int h[N], e[M], nxt[M], idx;
bool st[N];

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a]; h[a] = idx++;
}

// 以 u 为根，该连通区域内，子树的数量;
// 整体上，先检索链表找到节点，然后再用dfs搜索节点
int dfs(int u) {

    // 标记为搜索过
    st[u] = true;
    // sum 记录当前子树的大小，其本身就算是一个，因此默认值为1
    // res 记录每一个区域内连通块的最大值
    int sum = 1, res = 0;

    for (int i = h[u]; i != -1; i = nxt[i]) {

        // 先把编号取出来
        int j = e[i];
        if (!st[j]) {

            // 用s来表示当前子树的大小,迭代结束已经计算完全所有子节点，因此可以更新最大连通块了
            int s = dfs(j);
            // 当我们获知当前节点的子树之和时，首先更新最大连通块大小
            res = max(res, s);
            // 然后继续更新当前节点 u 其节点之和
            sum += s;
        }
    }
    // 当一次遍历结束时，说们当前节点的值已经更新结束，可以直接计算当前最大连通块大小了
    // 连通块大小，也可能来自于当前节点与所有节点的差值
    res = max(res, n - sum);
    // 更新结束后就计算目标值，即高峰中的山谷
    ans = min(ans, res);
    return sum;
}

int main(void) {

    cin >> n;

    // 将拉链链表的每个节点都重置为-1， 表示链表节点的终点
    memset(h, -1, sizeof h);

    for (int i = 0; i < n; i++) {

        int a, b;
        cin >> a >> b;
        // 无向边的双向连通，或者说是对射
        add(a, b), add(b, a);
    }

    // 输入节点编号从1开始
    dfs(1);

    cout << ans << endl;

    return 0;
}