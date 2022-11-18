#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e2 + 10, M = N * N / 2;

int n;
int q[N], d[N], h[N], e[M], nxt[M], idx;

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;
}

void topsort(void) {

    int hh = 0, tt = -1;

    // d[]������±��Ӧ���ǵڼ����ˣ�����϶��Ǵ�1��ʼ������
    for (int i = 1; i <= n; i++) {

        if (!d[i]) q[++tt] = i;
    }

    while (hh <= tt) {

        int t = q[hh++];

        for (int i = h[t]; i != -1; i = nxt[i]) {

            int j = e[i];
            d[j]--;
            if (d[j] == 0) q[++tt] = j;

        }
    }
}

int main(void) {

    cin >> n;

    memset(h, -1, sizeof h);

    // �����iָ�����Ǽ����ˣ����Լ�����1��ʼ
    for (int i = 1; i <= n; i++) {

        int son;
        while (cin >> son, son) {

            add(i, son);
            d[son]++;
        }
    }

    topsort();

    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}