#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void count_primes(int n) {

    for (int i = 2; i <= n; i++) {
        // 存储每一个质数，使用cnt标记质数个数
        // cnt作为primes每一个质数的下标和计数器，当然从0开始
        if (!st[i]) primes[cnt++] = i;
        // 以当前遍历到的数i，它作为模数被n取模运算的结果，以这个结果作为j下标的上限，枚举所有质数
        // j在此处作为下标[primes[j] <= n / i等价于 primes[j] * i <= n, 是我们欲删除的合数 ]
        // n / i 表达的上界是什么？因为primes[j] <= n / i， i 表达的是 n 与 最小质因数的倍数， 则上界表达的就是最小质因数
        for (int j = 0; primes[j] <= n / i; j++) {
            // 将每一个在 n / i之前的质数 与当前数i相乘得到的数字筛掉
            st[primes[j] * i] = true;
            // 如果当前数能够被其最小质数取模，则直接停止搜索
            if (i % primes[j] == 0) break;
        }
    }
}

int main(void) {

    int n;
    scanf("%d", &n);
    count_primes(n);
    printf("%d\n", cnt);

    return 0;
}

// 难点：内层循环上限的意义，如何求出某个数的最小质数
// 易错点：遍历每一个质数时上限为 n / i，而非 n % i, 内外层循环均能遍历到上限
// https://www.acwing.com/video/293/
// https://www.acwing.com/activity/content/code/content/49975/