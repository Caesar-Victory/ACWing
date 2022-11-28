#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

// Qָ���ǲ�ѯ����
int n, m, Q;
// �ڽӾ���洢ͼ
int d[N][N];


void floyd(void) {
    // K���������˼���պ���һ���ضϵ㣬Ҳ��һ��״̬
    // ������˵��kָ������·�� i - j ����ȥ k �ڵ�����о���
    // ��˶�̬�滮ʵ������һ����ά��
    // ת�Ʒ���Ϊ dist(i, j, k) = min(dist(im j, k-1), dist(i, k, k-1) + dist(k, j, k-1))
    for (int k = 1; k <= n; k++) {
        // �ڶ���������ѭ���ֱ�ö�������յ�
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n; j++) {

                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

}

// �ر�ֻ��Ҫ����������С�ı߼��ɣ��Ի�ֱ��ɾȥ
int main(void) {

    scanf("%d%d%d", &n, &m, &Q);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            // ָ���Լ��ľ���Ĭ��Ϊ0������Ĭ��Ϊ������
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    while (m--) {

        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);

        // �ر�ָ���Ƕ�ͬһ�������յ㣬�ύ��ͬ��Ȩ��
        // ��������ֻ����������̵��Ǹ�Ȩ��
        d[a][b] = min(d[a][b], w);

    }

    floyd();

    while (Q--) {

        int a, b;
        scanf("%d%d", &a, &b);
        // ��һ����̫���ֵ��Ϊ�ο�ϵ���������ֵ�Ŀ��ݶ�̫�󣬽��ϴ����̾���Ҳ�����Ҳ�����̾��봦��
        if (d[a][b] > INF / 2) puts("impossible");
        else printf("%d\n", d[a][b]);

    }

    return 0;
}
// https://www.acwing.com/activity/content/code/content/48531/
// https://www.acwing.com/video/286/