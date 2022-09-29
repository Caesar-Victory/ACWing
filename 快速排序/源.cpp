#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 数组,数组的长度和数组空间上限均声明为全局变量
// 如果不加 const 静态常量修饰符，N 实际值为 double类型，但声明类型为 int, 报错类型不一致
const int N = 1e6 + 10;

// 形参，也可以理解为默认值
int n;
int q[N];


void quick_sort(int q[], int l, int r) {

    if (l >= r) {
        return;
    }

    // 虚拟指针重定位，取出位序中点的值，便于操作数据
    int j = l - 1, k = r + 1, x = q[(l + r) >> 1];
    //int x = q[l], j = l - 1, k = r + 1;

    // 两层while循环，三个while语句；外围构建俩指针相遇，内围交换左右区间指针
    while (j < k) {

        do j++; while (q[j] < x);
        do k--; while (q[k] > x);

        if (j < k) {
            //swap(q[j], q[k]);
            int m = q[j];
            q[j] = q[k];
            q[k] = m;
        }
    }

    // 递归调用，区间仍为[l, r]，分界点为 k & k + 1
    quick_sort(q, l, k);
    quick_sort(q, k + 1, r);

}

int main() {

    // 获取用户输入的数组长度
    scanf("%d", &n);

    // 获取用户输入的数组
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    // 快速排序接受的是下标
    quick_sort(q, 0, n - 1);

    // 逐个打印排序后数组中每一个元素
    for (int i = 0; i < n; i++) {
        printf("%d", q[i]);
    }

    return 0;
}