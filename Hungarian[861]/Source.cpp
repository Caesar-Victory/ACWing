#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], nxt[M], idx;
int match[N];
bool st[N];

int find(int x) {

    // 枚举男生想要追求的所有女孩子
    for (int i = h[x]; i != -1; i = nxt[i]) {

        int j = e[i];

        if (!st[j]) {
            st[j] = true;
            // 女孩子没有对象，或者是可以挖其男朋友的墙角
            // 这个要去递归女孩子的对象，找她对象的多位女孩子，也可以立即为备胎，如果有她的男朋友还有备胎
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;
}

int main(void) {

    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m--) {

        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    // 统计可匹配的妹子总数
    int res = 0;

    // 这里遍历每一个男孩子，因为Match数组存储的是女孩子们的男朋友
    for (int i = 0; i <= n1; i++) {

        // 防止循环递归，假定该男生可以选择每一位女生，尝试找对象
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }

    printf("%d\n", res);

    return 0;
}
// 难点匹配对象的过程：待字闺中，据为己有【如果男孩子心仪的女孩子，这个女孩子没有对象就直接匹配】
// 女孩子match数组存储的是0，默认值，表示没有对象
// 名花有主，劝他放手【match数组中，女孩子存储的男朋友，如果这个男朋友还有其他心仪的对象，则现场匹配这位女孩子】
// 然后再劝她原来的对象放手
// https://www.acwing.com/video/290/
// https://www.acwing.com/video/290/