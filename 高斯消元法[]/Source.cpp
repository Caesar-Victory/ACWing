#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;

int n;
double a[N][N];

void out(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << a[i][j] << " ";
        }
        puts(" ");
    }
}
// 公用逻辑，先看操作是在那一个位置
// 高斯_约旦消元法
int gauss(void) {

    // 列，行
    int c, r;
    // 以西北角为源点，向右和向下为正增长区域
    // n 为 行， n + 1 为列
    for (c = 0, r = 0; c < n; c++) {
        // 用一个变量t存储绝对值最大的列，默认为当前列
        // for 循环，遍历当[前列的]所有行，找到绝对值最大的哪一行，将其赋值给变量t
        int t = r;
        // 从当前行开始，遍历所有的行
        for (int i = r; i < n; i++) {
            // 第 c 列的绝对值 大于 备选答案的绝对值
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }


        // 存值有误差，可能为0.00001，因此为避免精度问题重新设定标的
        // 当前绝对值最大的行[当前列] 仍然小于 0 则跳过
        if (fabs(a[t][c]) < eps) continue;



        // [与第一行 交换 列的绝对值最大的哪一行]的每一列
        for (int i = 0; i <= n; i++) swap(a[t][i], a[r][i]);

        // 将第一行的系数变为1，注意倒序，避免覆盖标的系数【标的指的是每一行首列数字的系数】
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];

        // 当前第c列的每一行全部重置为零
        // 遍历所有的行，起点为下一行：当前行 + 1，因为主元已经确认
        // 先向下，再向左
        for (int i = r + 1; i < n; i++) {
            // 对于当前列，遍历到的行的值大于0才开始操作
            if (fabs(a[i][c]) > eps) {
                // 逆序遍历列，由遍历到的行列 - 当前行的每一列 * 当前列的每一行
                // 不变的那一列与遍历顺序刚好相反，正向消零的时候可以到n
                for (int j = n; j >= c; j--) {
                    // 九宫格编码 8 = 2 * 4
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }

    // out();

    // 如何判断解的个数？以当前列为基准，遍历所有的行，只要有一个数值绝对值不为零
    if (r < n) {
        // 遍历最后一列的每一行
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) {
                return 2;  // 无解
            }
        }
        return 1;  // 无穷多组解
    }
    // 先由下到上，再从左到右
    // 逆序遍历所有的行，以当前行为基准，遍历其后所有的列
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // 最后一列的每一行 累减 最后一列的当前行，注意行列换坐标
            // 9 = 8 * 8
            a[i][n] -= a[i][j] * a[j][n];
        }
    }

    return 0;  // 有唯一解
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    int t = gauss();
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else {
        // 遍历所有的列
        for (int i = 0; i < n; i++) {
            // 如果列值小于极小，则重置为0
            if (fabs(a[i][n]) < eps) a[i][n] = 0;
            // 打印到小数点后两位，打印最后一列的所有行
            printf("%.2lf\n", a[i][n]);
        }
    }
    return 0;
}

// https://www.acwing.com/video/304/
// https://www.acwing.com/activity/content/code/content/53389/