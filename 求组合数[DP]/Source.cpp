#include <iostream>

using namespace std;

const int N = 2010, mod = 1e9 + 7;

int c[N][N];

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            // 现在有父集m,子集n，我们从父集m中选取n个元素；
            // 如果一个元素不在m中，则 c[i][j] = c[i - 1][j - 1]
            // 如果该元素在m中，c[i][j] = c[i - 1][j - 1]
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }

    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
    return 0;
}