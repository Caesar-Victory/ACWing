#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, F;
double a[N], s[N];

bool check(double avg) {
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - avg;
    double mins = 0;
    for (int k = F; k <= n; k++) {
        mins = min(mins, s[k - F]);
        if (s[k] >= mins) return true;
    }
    return false;
}

int main(void) {
    scanf("%d%d", &n, &F);
    double l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        r = max(r, a[i]);
    }
    while (r - l > 1e-5) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", (int)(r * 1000));
    return 0;
}

// 易错点：子函数大于等于的条件容易漏掉等于；取最大值中的较小值，在子函数求区间差时使用min函数
// https://www.acwing.com/video/86/
// https://www.acwing.com/activity/content/code/content/204001/