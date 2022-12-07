#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge {

    int a, b, w;
    // 小于符号 运算符重载，使得结构体支持sort()函数进行比较和排序
    bool operator< (const Edge& W) const {
        return w < W.w;
    };
} edges[N];

// 元素的集合[连通性]判断:下标是否与下标对应的数组元素相同
int find(int x) {

    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main(void) {

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {

        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a, b, w };
    }

    sort(edges, edges + m);

    // 初始化集合数组，给点标定初始集合
    for (int i = 1; i <= n; i++) p[i] = i;

    int res = 0, cnt = 0;

    for (int i = 0; i < m; i++) {

        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a); b = find(b);

        // 判断两个点的所属集合是否相同
        if (a != b) {

            // 让两个集合合并
            p[a] = b;
            // res存储的是最小生成树中，所有树边的权重之和
            res += w;
            // cnt 存储的是当前增加了多少条边
            cnt++;
        }
    }

    // 抽屉原理，cnt是最小生成树中节点个数, n个节点，对应 n - 1条边；
    if (cnt < n - 1) puts("impossible");
    else printf("%d\n", res);

    return 0;
}

// 难点：对结构体中权重属性的排序，实现方式：sort内部lambda匿名函数，运算符重载；
// https://www.acwing.com/video/288/
// https://www.acwing.com/activity/content/code/content/48773/