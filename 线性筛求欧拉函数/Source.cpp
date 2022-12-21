#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int primes[N], euler[N], cnt;
bool st[N];

void get_euler(int n) {
    // 与1互质的数是它本身，互质指的是两个或者多个数字的最大公约数为1【八竿子打不着的质数】
    // 仅有一个
    // 易错点：位序1容易错写为i
    euler[1] = 1;
    // 易错点，遍历的起点是最小质数2
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            // 如果一个数是质数，则它的欧拉函数为该质数 - 1
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                // 如果遇到最小质数primes[j]的i倍，则其欧拉函数等于primes[j]倍的[i的欧拉函数]
                euler[primes[j] * i] = primes[j] * euler[i];
                break;
            }
            // 如果primes[j]不是i的质因数，那么它的欧拉函数等于[primes[j] - 1]倍的[i的欧拉函数]
            euler[primes[j] * i] = (primes[j] - 1) * euler[i];
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    LL res = 0;
    get_euler(n);
    for (int i = 1; i <= n; i++) res += euler[i];
    cout << res << endl;
    return 0;
}

// https://www.acwing.com/video/28/
// https://www.acwing.com/activity/content/code/content/49995/