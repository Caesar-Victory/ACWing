#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int quickmi(int a, int b, int p) {
    // 处理特例，除了0，1以外的任何正整数，它mod1的结果均为0，因为均为1的整数倍，没有余数
    // p = 1, b = 0
    int res = 1 % p;
    while (b) {
        // 如果k的二进制表达，末尾为1，则直接相乘
        if (b & 1 == 1) res = (LL)res * a % p;
        // K右移一位，删除末尾
        b >>= 1;
        // (x * y) % p = (x % p * y % p) % p;
        // 每乘以一次a,相当于幂次加1，也就相当于幂次部分每次加1，也就是 + 2 ^ 0
        // 将指数的二进制表示看作一个滑窗，反复平方要表达的是，当遇到位上为1，则直接让返回值乘以底数
        // 当位上为0时，则用以下代码，把幂次中2的幂次加1
        // 谁作为底数，就对谁的幂次+1
        // 易错点，容易将左值写为res
        a = (LL)a * a % p;
    }
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%d\n", quickmi(a, b, p));
    }
    return 0;
}

// https://www.acwing.com/activity/content/code/content/50237/
// https://www.acwing.com/video/300/
// https://oi-wiki.org/math/binary-exponentiation/
// https://zh.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E6%B1%82%E5%B9%82