#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int h[N];

// 如果待查找的值在h[] 数组当中，直接返回位序，不在则返回适合其插入的位置
int find(int x) {

    int k = (x % N + N) % N;
    // 如果当前位序存储的值，不是默认值，并且也不是我们待寻找的值，则一路向下寻找
    while (h[k] != null && h[k] != x) {
        k++;
        // 当我们完成一次长度为N的遍历之后，从头开始遍历
        if (k == N) k = 0;
    }
    return k;
}

int main(void) {

    int n;
    scanf("%d", &n);

    // int 是四个字节，因此这里的3f会被拷贝为4次的结果，如 0x3f3f3f3f
    memset(h, 0x3f, sizeof h);

    while (n--) {

        int x;
        char op[2];
        scanf("%s%d", op, &x);
        // 首先在 h[] 数组中招到待查找的值
        int k = find(x);
        // 如果这个值并不存在，则将当前位序赋值为 x
        if (*op == 'I') h[k] = x;
        else {
            // 如果这个值已经存储在 h[] 数组当中，并且不为空
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}