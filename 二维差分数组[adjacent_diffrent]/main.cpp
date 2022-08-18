#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int a[N][N], b[N][N];
int n, m, q;

void insert(int x1, int y1, int x2, int y2, int c) {
    // �ȼ���С�����
    b[x1][y1] += c;
    // ���������ƶ�
    b[x2 + 1][y1] -= c;
    // ���������ƶ�
    b[x1][y2 + 1] -= c;
    // ������С��������
    b[x2 + 1][y2 + 1] += c;
}

int main() {

    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            insert(i, j, i, j, a[i][j]);
        }
    }

    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // ����д���˴�Ϊ�ۼ�
            // �����߼��������������������С�����������ȥС���������
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        // ��ӡһ������������һ���ո� ���ڷ���
        for (int j = 1; j <= m; j++) {
            printf("%d ", b[i][j]);
        }
        puts(" ");
    }

    return 0;
}