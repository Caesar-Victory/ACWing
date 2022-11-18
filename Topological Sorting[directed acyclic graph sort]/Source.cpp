#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N], d[N], h[N], e[N], nxt[N], idx;

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;

}

bool topsort(void) {

    // ������е���û�в���Ԫ�أ���ֱ�ӽ�βָ�붨��Ϊ-1
    int hh = 0, tt = -1;

    // �ڵ��Ŵӿ�ʼ�����i����Ϊ1
    for (int i = 1; i <= n; i++) {

        // �����Ϊ0�Ľڵ�װ����е���
        if (!d[i]) q[++tt] = i;

    }

    // �����в�Ϊ��ʱ
    while (hh <= tt) {

        // ��βȡ��Ԫ��
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = nxt[i]) {

            int j = e[i];
            d[j]--;
            if (d[j] == 0) q[++tt] = j;
        }

    }

    return tt == n - 1;

}

int main(void) {


    cin >> n >> m;

    // �ڽӱ��������ڵ�ֵ��ʼ��Ϊ-1�� -1��ʾ�ڵ�Ϊ��
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;
        add(a, b);
        // Ӧ�����յ�����
        d[b]++;
    }

    if (topsort()) {

        for (int i = 0; i < n; i++) printf("%d ", q[i]);

    }

    else puts("-1");

    return 0;
}