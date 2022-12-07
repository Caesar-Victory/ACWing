#include <cstdio>

using namespace std;

bool primes(int x) {
    // 边界检查，小于2一定没有质数
    if (x < 2) return false;
    // 因为仅需要判断质数，如果一个数 i 为 x 的合数，那么  x / i 也是 x 的合数
    // 他俩总是成对出现，由于仅需要判断是否为质数，因此我们只需要枚举 x/i的部分即可
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int main(void) {

    int n;
    scanf("%d", &n);
    while (n--) {

        int m;
        scanf("%d", &m);
        if (primes(m)) puts("Yes");
        else puts("No");
    }
    return 0;
}