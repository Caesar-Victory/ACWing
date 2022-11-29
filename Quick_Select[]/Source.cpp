#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int q[N];


int quick_select(int l, int r, int k) {

    if (l == r) return q[l];

    int x = q[l], i = l - 1, j = r + 1;

    while (i < j) {

        do ++i; while (q[i] < x);
        do --j; while (q[j] > x);

        if (i < j) swap(q[i], q[j]);
    }
    // L是左边界点，J为虚拟指针，是变点，也是左区间的上限，+1是为了将计数转为位序
    // S1代表的是左区间已经排序的元素个数
    int s1 = j - l + 1;
    // 快速选择并不递归访问双边，而是只递归进入一边的元素中继续寻找
    if (k <= s1) return quick_select(l, j, k);
    return quick_select(j + 1, r, k - s1);
}

int main(void) {

    cin >> n >> k;

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    cout << quick_select(0, n - 1, k) << endl;

    return 0;

}
