#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
// @size: 当前堆有多少个元素
// 堆是用数组线性存储的，那么下标小的就是父节点，下标大的就是儿子节点
int h[N], scale;

void down(int u) {
    // @t: 表示三个点中的最小值；
    // 此操作是将位序 u 拷贝下来，并且计算原坐标
    int t = u;
    // 存在左儿子，并且左儿子的值比需要移动的节点小
    if (u * 2 <= scale && h[u * 2] < h[t]) t = u * 2;
    // 存在右儿子，右儿子的值比需要移动的节点小
    if (u * 2 + 1 <= scale && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    // 这里的意思是每找到一个新的坐标【左右节点】，就交换他俩的值并且迭代，直到满足堆定义
    // 易错点：容易写为while语句
    if (u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u) {

    // 父节点比当前这个点还要大，则将其换上去
    while (u / 2 && h[u / 2] > h[u]) {
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main(void) {

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);

    // 建堆之前必做的操作；
    // 将堆的容积重置为节点个数，因为我们将从数组的末尾开始down()每一个元素
    scale = n;

    for (int i = n / 2; i; i--) down(i);

    while (m--) {
        printf("%d ", h[1]);
        // 交换尾巴节点和堆顶节点
        h[1] = h[scale];
        // 规模减一意味着删除
        scale--;
        // 堆顶元素被重新赋值后，其与左右节点的大小关系可能发生变化，故此down()操作一下
        // 易错点 1 容易错写为 i
        down(1);
    }

    return 0;
}

// https://www.acwing.com/video/263/
// https://www.acwing.com/activity/content/code/content/45296/