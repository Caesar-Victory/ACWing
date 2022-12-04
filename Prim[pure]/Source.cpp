#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

// ���ڵ���߱���--->֪����ͼ
const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim(void) {

    // �Ȱ����о����ʼ��Ϊ������
    memset(dist, 0x3f, sizeof dist);

    // ��С���������棬���бߵĳ���֮��
    int res = 0;

    // ÿһ�α����ҵ���ǰ�����⣬������̵ĵ�
    // ÿһ�ε��������·��ʱ���Ѿ����������·���ܳ��ȣ���˱��� n �Σ������� n - 1��
    for (int i = 0; i < n; i++) {

        int t = -1;

        for (int j = 1; j <= n; j++)
            // �����⣬û�ҵ��κ�һ���� | t �ľ������ j �ľ���
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                // t �洢��ǰ������С�ĵ�
                t = j;


        // ���ǵ�һ���㣬���Ҿ�����������˵���뵱ǰ���Ͼ�������ĵ㣬��Ϊ������
        // ͼ����ͨ����������С������
        if (i && dist[t] == INF) return INF;
        // ֻҪ���ǵ�һ���ߣ����Ǿͽ������ۼӵ����ϵ���ȥ
        if (i) res += dist[t];
        // Prim �㷨�� dist[t] ��ʾ �� t �����ϵľ���
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
        // ���뵽���ϵ��У�������Ϊtrue
        st[t] = true;
    }
    return res;
}

int main(void) {

    scanf("%d%d", &n, &m);

    // �����ֵ��Ҫ������������Ϊ˫��ѭ������д��Ч�ʸ���
    memset(g, 0x3f, sizeof g);

    while (m--) {

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);

    }

    int t = prim();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}