#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        int res = a;
        for (int i = 2; i <= a / i; i++) {
            if (a % i == 0) {
                // res = res * (1 - 1 / a);
                // 先计算除法，避免溢出；转换为long long 类型就可以不调整运算顺序
                // es = 1LL * res * (a-1) / a;
                // 可以类比 Sn前 n 项和
                res = res / i * (i - 1);
                while (a % i == 0) a /= i;
            }
        }
        // 易错点，特判是处理仅有自身和1的较大质数，因此必定在for循环之后
        if (a > 1) res = res / a * (a - 1);
        cout << res << endl;
    }
    return 0;
}

// https://www.acwing.com/video/298/
// https://www.acwing.com/activity/content/code/content/49992/