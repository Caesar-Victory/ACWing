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
            // �����и���m,�Ӽ�n�����ǴӸ���m��ѡȡn��Ԫ�أ�
            // ���һ��Ԫ�ز���m�У��� c[i][j] = c[i - 1][j - 1]
            // �����Ԫ����m�У�c[i][j] = c[i - 1][j - 1]
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