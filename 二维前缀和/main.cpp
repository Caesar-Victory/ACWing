#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int e[N][N], l[N][N];
int n, m, q;

int main() {

    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &e[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            l[i][j] = l[i - 1][j] + l[i][j - 1] - l[i - 1][j - 1] + e[i][j];

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", l[x2][y2] - l[x1 - 1][y2] - l[x2][y1 - 1] + l[x1 - 1][y1 - 1]);
    }

    return 0;
}