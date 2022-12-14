#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];


// 返回数值x 所在的集合编号/返回 x 的祖宗节点  + 路径压缩【并查集优化】
int find(int x) {
    // 如果节点的值不是根节点的值，那么递归寻找它的相对祖宗节点
    // 路径压缩，将当前节点的值赋值为父亲节点的值，则会导致树进化为数组
    // 从节点直连到根节点
    // 把当前节点的值，换为找到的爸爸，不管是不是自己的爸爸
    if (p[x] != x) p[x] = find(p[x]);
    // 易错点 容易把代码错写为 p[x] == find(p[x])
    return p[x];
}

int main(void) {

    // 先读入操作的点和操作的数量
    scanf("%d%d", &n, &m);
    // 初始化时，相当于生成了一个位序和值相等的哈希表【初始状态每一个集合的节点均指向根节点，也就是它本身】
    // 每一个集合编号/根节点，其节点的值指向/存储本身；注意需要遍历到N
    for (int i = 0; i <= n; i++) p[i] = i;
    while (m--) {
        // 读取字符串类型 %s 会自动忽略空格和回车，避免因为 %c 读取错误的空格和回车
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        // 注意此处的是字母 也就是单字符 用单引号
        if (op[0] == 'M') {
            // a 的祖宗节点指向 b 的祖宗节点【赋值的形式】
            // 给a节点找爸爸，用P数组更换下标的方式，看看是不是b节点的爸爸
            // 可以用find(int x) 函数根据路径找父节点的逻辑理解 p[x] = find(p[x])
            // 相当于在 find(b) = find(a)，对左边的递归加了一层读取，其目的是为为了修改a节点父亲节点
            // 达到将a父亲节点全部等于b的祖宗节点，换句话说是将一整棵子树全部修改为一个祖宗
            p[find(a)] = find(b);
        }
        else {
            // 如果 a, b 节点的爸爸相等，则返回 否则返回
            // 不能确定所有的节点以及被路径压缩，因此需要递归查找
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

//  易错点：char数组无需指定位序；
//  https://www.acwing.com/video/261/
//  https://www.acwing.com/activity/content/code/content/45287/