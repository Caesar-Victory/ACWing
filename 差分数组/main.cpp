#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m;

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

/// 快速处理区间加减操作【指定区间的左加右减可以保持平衡，由于前缀和是区间和，因此只会影响插入区间端点右侧的数值】
/// 询问区间和问题【差分逆向求前缀和 s[n] = d[r] - [l - 1]】
int main() {

    scanf("%d%d", &n, &m);

    // 读入原始数组
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    // 将原始数组插入差分数组
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        // 特定区域插入值
        insert(l, r, c);
    }

    // 差分计算
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

    // 输出
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;

}