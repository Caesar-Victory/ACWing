#include <cstdio>

using namespace std;

int n;

void get_primes(int n) {

    // 缩减规模，成对出现的和数，每次枚举一对中较小的哪一个，使得复杂度为sqrt(n)
    for (int i = 2; i <= n / i; i++) {

        if (n % i == 0) {

            int s = 0;
            // 循环累除，求出幂次
            while (n % i == 0) {

                n /= i;
                s += 1;

            }
            // 循环结束后立即输出幂次和i，因为n已经被模运算以及累除，此时为n的一个合数
            printf("%d %d\n", i, s);
        }
    }
    // for循环结束表示该数n为质数，没有合适的合数，直接返回其本身和1即可
    if (n > 1) printf("%d %d\n", n, 1);
    puts("");
}

int main(void) {

    scanf("%d", &n);
    while (n--) {

        int m;
        scanf("%d", &m);
        get_primes(m);
    }

    return 0;
}

// 易错点：容易搞错特判逻辑的位置，在for循环结束后
// https://www.acwing.com/video/292/
// https://www.acwing.com/activity/content/code/content/49974/