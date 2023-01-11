#include <iostream>

using namespace std;

typedef long long LL;

int quickmi(int a, int b, int p) {
    int res = 1 % p;
    while (b) {
        if (b & 1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, p;
        scanf("%d%d", &a, &p);
        // ��ʽΪ b ^ (p - 2) ͬ���� 1 (mod p)
        if (a % p) printf("%d\n", quickmi(a, p - 2, p));
        else puts("impossible");
    }
    return 0;
}
// ����С���� https://zh.wikipedia.org/wiki/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86
// https://www.acwing.com/video/301/
// https://www.acwing.com/activity/content/code/content/50238/