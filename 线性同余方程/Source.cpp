#include <iostream>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    // 原方程为 ax + b(y - a / b * x) = d
    y -= a / b * x;
    return d;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        // x是a的系数， y是待定系数
        int x, y;
        // d 指的是gcd(a, b)最大公约数
        int d = exgcd(a, m, x, y);
        // b 是余数，m 是模数中第二个参数
        if (b % d) puts("impossible");
        // 对结果 % m 是为了保证输出的值在2e9以内[剩余系]
        // m 是同余数  不是随便选取的模数
        else printf("%d\n", (LL)b / d * x % m);
    }
    return 0;
}


//  易错点：扩展欧几里得算法内部递归时忘记交换x, y传参位置；给欧几里得传参时传错参数应当是m，
// 这才是模运算的第二个参数
//  https://www.acwing.com/video/303/
//  https://www.acwing.com/activity/content/code/content/50248/
//  剩余系  https://baike.baidu.com/item/%E5%89%A9%E4%BD%99%E7%B3%BB/4644262
