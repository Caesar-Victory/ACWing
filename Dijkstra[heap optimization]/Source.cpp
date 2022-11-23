#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

// 队列中的数值按照哈希对：距离，节点编号存储
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n, m;
int h[N], w[N], e[N], nxt[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {

    e[idx] = b, w[idx] = c, nxt[idx] = h[a], h[a] = idx++;

}



int dijkstra(void) {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 优先队列中每个元素都是pair类型
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    // 值为零，编号为1
    heap.push({ 0, 1 });

    while (heap.size()) {

        // 首先优先队列中读取堆顶元素，然后删除
        auto t = heap.top();
        heap.pop();

        // 分别通过变量重命名节点编号和距离
        int ver = t.second, distance = t.first;

        // 找到的最小值，可能之前已经确定过了，注意这里选取的对象【下标】是节点
        // 去重操作
        if (st[ver]) continue;
        // 并且将最短距离标记为已确定【这段代码看起来像是废话，去掉后又会TLE】
        st[ver] = true;

        // 通过局部变量 ver 节点编号从链表穿层
        // 遍历所有点的出边就是遍历所有边；【单向连接性】
        for (int i = h[ver]; i != -1; i = nxt[i]) {

            // 取出每一个节点编号
            int j = e[i];

            // 当前节点编号的距离，是否大于队列中存储的距离  + 其权重
            if (dist[j] > distance + w[i]) {

                // 重新赋值，再次放入队列
                dist[j] = distance + w[i];
                heap.push({ dist[j], j });
            }

        }
    }

    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];

}

int main(void) {

    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {

        int a, b, c;
        cin >> a >> b >> c;

        add(a, b, c);

    }

    int t = dijkstra();

    printf("%d\n", t);

    return 0;
}