#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;


const int mod = 1e9 + 7;

int main(void) {

    int n;
    scanf("%d", &n);
    unordered_map<int, int> primes;
    while (n--) {
        int m;
        scanf("%d", &m);
        for (int i = 2; i <= m / i; i++) {
            // 同时获取质数及其指数
            while (m % i == 0) {
                m /= i;
                primes[i]++;
            }
        }
        // 若一个指数只有它本身与1，则直接对该质数计数
        if (m > 1) primes[m]++;
    }

    long long res = 1;
    // 质数和公式：循环累乘：（每个质数 + 1）
    for (auto prime : primes) res = ((res * (prime.second + 1)) % mod);
    cout << res << endl;
    return 0;
}

// 易错点：求取质数及其质数时，不必枚举每个数字；不必特判质数为某个数的平方根的情况
// 因为同时统计指数和指数，且其指数为2
// // https://www.acwing.com/video/295/
// https://www.acwing.com/problem/content/872/