#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int N = 7;
int n;
int path[N];
bool st[N];

void dfs(int u) {

    // 递归结束的条件是：用于标记衍生字符串产长度的变量 u 与 主串长度相等
    if (u == n) {
        for (int i = 0; i < n; i++) printf("%d ", path[i]);
        puts(" ");
        return;
    }

    // 枚举的是值域 [1, n]
    // 递归前后需要修改数字的状态，使用布尔值标记该数字是否被使用 --- 恢复现场
    for (int i = 1; i <= n; i++) {
        // st[]  数组按照值标记是否被用过
        // path[] 数组按照下标 标记长度为 n 数组，那个位序上存储了那个值
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            // 恢复现场: path[u] 每次只存储一个值，因为回溯会反复擦写，因此不必使用 path[u] = 0 来
            st[i] = false;
        }
    }
}

int main(void) {

    cin >> n;
    dfs(0);
    return 0;
}