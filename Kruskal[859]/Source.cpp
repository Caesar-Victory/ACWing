#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge {

    int a, b, w;
    // С�ڷ��� ��������أ�ʹ�ýṹ��֧�ֱȽϺ�����
    bool operator< (const Edge& W) const {
        return w < W.w;
    };
} edges[N];

// Ԫ�صļ����ж�
int find(int x) {

    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main(void) {

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {

        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a, b, w };
    }

    sort(edges, edges + m);

    // ��ʼ���������飬����궨��ʼ����
    for (int i = 1; i <= n; i++) p[i] = i;

    int res = 0, cnt = 0;

    for (int i = 0; i < m; i++) {

        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a); b = find(b);

        // �ж�����������������Ƿ���ͬ
        if (a != b) {

            // ���������Ϻϲ�
            p[a] = b;
            // res�洢������С�������У��������ߵ�Ȩ��֮��
            res += w;
            // cnt �洢���ǵ�ǰ�����˶�������
            cnt++;
        }
    }

    if (cnt < n - 1) puts("impossible");
    else printf("%d\n", res);

    return 0;
}