#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], nxt[N], idx;
// 到达每一个点的距离，用于BFS搜索的队列
int d[N], q[N];


void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;
}

int bfs() {

    // 设定队列的队头指针和队尾指针
    int hh = 0, tt = 0;
    // 第一个入队的元素是节点1
    q[0] = 1;
    memset(d, -1, sizeof d);
    // 节点1的初始距离为1
    d[1] = 0;

    while (hh <= tt) {

        // 取出队头元素
        int t = q[hh++];

        // 遍历链表取得节点
        for (int i = h[t]; i != -1; i = nxt[i]) {

            // 存储节点的值
            int j = e[i];
            // 检查节点是否被搜索过
            if (d[j] == -1) {
                // 动态规划/前缀和，获得累加
                d[j] = d[t] + 1;
                // 从队尾插入元素
                q[++tt] = j;
            }
        }
    }

    // 返回节点n 的距离
    return d[n];
}


// 自环指的是自己指向自己 my = self, 重边指的是 A ---> B 同时有两条边指向目的地
int main(void) {

    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        // a 为起点，b 为终点，绑定有向关系
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}