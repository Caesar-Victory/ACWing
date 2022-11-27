#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], nxt[N], w[N], idx;
int dist[N];
// st数组用来表示该节点是否在队列当中
bool st[N];

void add(int a, int b, int c) {

    e[idx] = b, w[idx] = c, nxt[idx] = h[a], h[a] = idx++;

}

// 重点：st数组的作用？前式链向星？；控制输出时为何不需要对最大值除以2【拟合】？
void spfa(void) {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 已访问过的节点，还会再次被访问；节点指向多个邻边时，每次更新则会使用前驱节点
    // 这里不是标记已搜索，而是降重加快速度
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {

        int t = q.front();
        q.pop();
        st[t] = false;

        // 从队头中取出节点编号，更新其邻边
        for (int i = h[t]; i != -1; i = nxt[i]) {

            int j = e[i];

            if (dist[j] > dist[t] + w[i]) {

                dist[j] = dist[t] + w[i];

                if (!st[j]) {

                    q.push(j);
                    st[j] = true;

                }

            }
        }
    }
}

int main(void) {

    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);

    }

    spfa();
    if (dist[n] >= 0x3f3f3f3f) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}
// https://www.acwing.com/video/283/
// https://www.acwing.com/activity/content/code/content/48498/
// 需要特别注意，随着节点出队和入队，一定要完成存在性标记
// 节点和邻边节点容易搞混