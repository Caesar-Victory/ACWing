#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N], d[N], h[N], e[N], nxt[N], idx;

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;

}

bool topsort(void) {

    // 如果队列当中没有插入元素，则直接将尾指针定义为-1
    int hh = 0, tt = -1;

    // 节点编号从开始，因此i至少为1
    for (int i = 1; i <= n; i++) {

        // 将入度为0的节点装入队列当中
        if (!d[i]) q[++tt] = i;

    }

    // 当队列不为空时
    while (hh <= tt) {

        // 队尾取出元素
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = nxt[i]) {

            int j = e[i];
            d[j]--;
            if (d[j] == 0) q[++tt] = j;
        }

    }

    return tt == n - 1;

}

int main(void) {


    cin >> n >> m;

    // 邻接表的主链表节点值初始化为-1， -1表示节点为空
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;
        add(a, b);
        // 应当对终点记入度
        d[b]++;
    }

    if (topsort()) {

        for (int i = 0; i < n; i++) printf("%d ", q[i]);

    }

    else puts("-1");

    return 0;
}