#define  _CRT_SECURE_NO_WARNINGS
// 值域和定义域不匹配，规模相差较大1.9 * 1e10
// 成员判断是否通过遍历匹配的方式验证
// 先求大于 1e5 的第一个质数
#include <cstring>
#include <iostream>

using namespace std;

// 可以将空间开为两倍，且以质数形式约束，尽可能降低碰撞的概率
const int N = 100003;

// 分别表示插槽，e:存储的值，ne:下一个值在哪一个位置【链接关系】
// idx 表示当前用到了哪一个位置
int h[N], ne[N], e[N], idx;

// 想一个函数，完成哈希映射 也就是 +- 1e9 ---> 1e5
void insert(int x) {

    // +N 再 % N 目的是让余数始终保持为正数
    // 对于取模运算来说，N为正，结果为正；N为负，结果为负；
    // 先取模再加，前者整体再取模，因为 输入值 x 与 N 相差的1e9的数量级，如果先求和，N不够与 X对冲，使其成为一个正数
    // 此处使用如此复杂的取模，求和，再取模就是为了当 X 的值为负数时，输出仍然为正数
    // 可知: k 即将作为哈希表的下标
    int k = (x % N + N) % N;
    // 先把这个点存储下来
    e[idx] = x;
    // 用next 数组，以当前 idx 的值作为索引，将该位序的值赋值为 h[k]， 此时h[k]与idx等价，都是充当数组的位序
    ne[idx] = h[k];
    // 非本体
    h[k] = idx++;
    // K 就是哈希值

}

bool find(int x) {

    int k = (x % N + N) % N;
    // 首先找到哈希表中的映射点，转入链表中开始搜索值
    // 让 h[k]充当下标，此处h[k]可以理解为引子，从哈希表转战到链表当中
    // h[k] 存储的是第一个节点的下标
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}

int main(void) {
    int n;
    scanf("%d", &n);

    // 在将元素插入链表前，先把槽清空，空指针一般用 -1 来表示
    // 将 h[] 数组中的值全部初始化为-1， 把所有单链表头指针初始化为-1
    // 头文件：csting
    memset(h, -1, sizeof h);

    while (n--) {
        char op[2];
        int x;
        // 用 %s 读取字符，会主动丢弃空格，回车和换行符
        scanf("%s%d", op, &x);

        // 注意此处为 单引号 'I' 双引号会导致字符数组中的字符，与常量 字符不匹配
        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}

// 代码讨论区
// https://www.acwing.com/activity/content/code/content/45308/
// 视频题解讨论区
// https://www.acwing.com/video/266/
// 避免哈希碰撞的两种方式，以及memset的深层控制【未吸收】
// https://www.acwing.com/solution/content/33699/
// https://www.cnblogs.com/east7/p/12594894.html
// 拓展阅读 0x3f
// https://blog.csdn.net/lyj2014211626/article/details/65481630