#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, mod = 1e9 + 7;;

int fact[N], infact[N];

int qmi(int a, int k, int p) {
    // 乘数因子，初始化为1
    int res = 1;
    // k 每次以位运算的方式除以2
    while (k) {
        // 如果当前数末尾为1，说明此位被选取，于是用res保存的上一次的值累乘
        if (k & 1) res = (LL)res * a % p;
        // 否则对 a 平方再取模，这是便于在遇到 101 的情况，位数能够及时的扩大 2 倍
        a = (LL)a * a % p;
        // k 每次以位运算的方式除以2
        k >>= 1;
    }
    return res;
}

int main(void) {

    // 对于组合数中的较大数字，要使用递推式先求出阶乘
    // 对于组合中的较小数字，在使用递推式求出阶乘时，需要乘以其快速幂，将其从除数转换为乘数
    // 两者都需要在计算过程中开 long long 以及取模，对于当前数 i ， 其指数为 mod - 2, 模数为mod
    // 费马小定理
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        // infact[i] = (LL)qmi(fact[i], mod - 2, mod) % mod; //通过fact求infact
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        // 在组合公式的基础上，对于分子求阶乘，乘以组合数中较小值的逆元，以及组合中俩差值的逆元
        // 每两次乘法运算，取模一次
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }

    return 0;
}

// 易错点，快速幂中指数k每次除以 2 仅写向右位移一位，忘记写等号
// 阶乘运算，遍历起点是1，而非0
// 费马小定理： https://zh.wikipedia.org/wiki/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86
// https://www.acwing.com/video/307/
// https://www.acwing.com/activity/content/code/content/53394/