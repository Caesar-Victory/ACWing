#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

// 将数据类型的标识符重新定义 是为了节省敲代码的时间
typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

ULL h[N], p[N];
int n, m;
// 用数组存储每一个输入的字母
char str[N];

ULL get(int l, int r) {

    // 相当于公式 h[n] - h[n-1] * p ^ (l - r + 1)
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(void) {

    scanf("%d%d%s", &n, &m, 1 + str);

    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        // p[] 数组存储的是P值的次方，位序即幂次
        p[i] = p[i - 1] * P;
        // h[] 数组存储的是字符串前缀哈希值，直接 + ascⅡ码
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}