#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], nxt[N], w[N], idx;
int dist[N];
// st����������ʾ�ýڵ��Ƿ��ڶ��е���
bool st[N];

void add(int a, int b, int c) {

    e[idx] = b, w[idx] = c, nxt[idx] = h[a], h[a] = idx++;

}

// �ص㣺st��������ã�ǰʽ�����ǣ����������ʱΪ�β���Ҫ�����ֵ����2����ϡ���
void spfa(void) {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // �ѷ��ʹ��Ľڵ㣬�����ٴα����ʣ��ڵ�ָ�����ڱ�ʱ��ÿ�θ������ʹ��ǰ���ڵ�
    // ���ﲻ�Ǳ�������������ǽ��ؼӿ��ٶ�
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {

        int t = q.front();
        q.pop();
        st[t] = false;

        // �Ӷ�ͷ��ȡ���ڵ��ţ��������ڱ�
        for (int i = h[t]; i != -1; i = nxt[i]) {

            int j = e[i];

            if (dist[j] > dist[t] + w[i]) {

                dist[j] = dist[t] + w[i];

                if (!st[j]) {

                    q.push(j);
                    st[j] = true;

                }

            }
        }
    }
}

int main(void) {

    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);

    }

    spfa();
    if (dist[n] >= 0x3f3f3f3f) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}
// https://www.acwing.com/video/283/
// https://www.acwing.com/activity/content/code/content/48498/
// ��Ҫ�ر�ע�⣬���Žڵ���Ӻ���ӣ�һ��Ҫ��ɴ����Ա��
// �ڵ���ڱ߽ڵ����׸��