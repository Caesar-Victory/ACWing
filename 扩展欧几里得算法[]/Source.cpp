#include <iostream>

using namespace std;

// 传引用，需要带回计算后的x, y
int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    // 交换x, y的位置,使得他们与a,b的参数位置对应
    int d = exgcd(b, a % b, y, x);
    // 用子问题的结果来计算当前问题的结果，递归结束后再算y
    y -= a / b * x;
    return d;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}
// 易错点：忘记x, y是传引用，写两个&符号
// 计算后需要返回余数，且用变量接收余数，便于计算y值
// https://www.acwing.com/video/302/
// https://www.acwing.com/activity/content/code/content/50245/