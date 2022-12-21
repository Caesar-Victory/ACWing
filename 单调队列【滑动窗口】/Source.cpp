#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], q[N];

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    // 队头与队尾，可以看作初始长度为1的数组
    // 对于一个非空的队列来说，队头在左端点，队尾在右端点
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        // 判断队头是否在窗口内部，如果不在，就把它删掉
        // 存储队列元素下标的数组，其队头元素【下标】是否越过单调队列的下限
        // 单调队列的下限怎么计算？当前位序 - k [单调队列的长度] + 1
        if (hh <= tt && q[hh] < i - k + 1) hh++;
        // while循环剔除单调队列中所有大于等于当前元素的
        // 注意：数组中队尾元素 与 当前遍历的元素之间的关系，刚好与所求相反
        // 对于求下一个更小元素，则两者关系为大于等于
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        // 把当前遍历到的这个数加入到队列当中
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        // 判断队头是否在窗口内部，如果不在，就把它删掉
        if (hh <= tt && q[hh] < i - k + 1) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        // 把当前遍历到的这个数加入到队列当中
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    return 0;
}