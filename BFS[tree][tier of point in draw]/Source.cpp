#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], nxt[N], idx;
// ����ÿһ����ľ��룬����BFS�����Ķ���
int d[N], q[N];


void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;
}

int bfs() {

    // �趨���еĶ�ͷָ��Ͷ�βָ��
    int hh = 0, tt = 0;
    // ��һ����ӵ�Ԫ���ǽڵ�1
    q[0] = 1;
    memset(d, -1, sizeof d);
    // �ڵ�1�ĳ�ʼ����Ϊ1
    d[1] = 0;

    while (hh <= tt) {

        // ȡ����ͷԪ��
        int t = q[hh++];

        // ��������ȡ�ýڵ�
        for (int i = h[t]; i != -1; i = nxt[i]) {

            // �洢�ڵ��ֵ
            int j = e[i];
            // ���ڵ��Ƿ�������
            if (d[j] == -1) {
                // ��̬�滮/ǰ׺�ͣ�����ۼ�
                d[j] = d[t] + 1;
                // �Ӷ�β����Ԫ��
                q[++tt] = j;
            }
        }
    }

    // ���ؽڵ�n �ľ���
    return d[n];
}


// �Ի�ָ�����Լ�ָ���Լ� my = self, �ر�ָ���� A ---> B ͬʱ��������ָ��Ŀ�ĵ�
int main(void) {

    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        // a Ϊ��㣬b Ϊ�յ㣬�������ϵ
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}