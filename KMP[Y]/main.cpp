#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int nxt[N];

int main(void) {

    // 下标从1开始匹配
    cin >> n >> p + 1 >> m >> s + 1;

    // 求 nxt数组过程 i = 1时，nxt[i] = 0,为全局变量：数组中每一个元素的默认值
    // 也可以理解为：满足公共前后缀的前提是：至少有两个字符
    for (int i = 2, j = 0; i <= n; i++) {

        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        // 修改数组，将当前位序的值修改为J
        nxt[i] = j;
    }


    // 主串遍历从位序1，也就是从头开始，模式串指针 J 往前错开一位，从0开始
    for (int i = 1, j = 0; i <= m; i++) {

        // J 没有回退到0,且两个元素不同
        while (j && s[i] != p[j + 1]) j = nxt[j];
        // 符号匹配则继续向右移动模式串指针J，或者说 匹配字符长度累加
        if (s[i] == p[j + 1]) j++;
        // J 指针的长度 与 n 模式串长度相等
        if (j == n) {

            // 匹配成功, 位序从0开始计数 则无需+1 直接 i - n
            printf("%d ", i - n);
            // 匹配成功再后退一步
            j = nxt[j];
        }
    }

}