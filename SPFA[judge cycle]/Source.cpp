#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int h[N], e[N], nxt[N], w[N], idx;
// ����Ϊȫ�ֱ������ȼ����趨Ĭ��ֵ0����ʵ����Ϊ�κ�ֵ������
// ʹ��memset()���Խ�������Ϊ0x3f, 0x7f, 127,128
// Ҳ�������Ϊ����Դ�㣬����ÿһ���ڵ����ӣ���Ϊÿһ���ڵ��ǰ������Ȩ��Ϊ0������ԭͼ�ĸ�Ȩ��·�������Ӻ����ͼ�ĸ�Ȩ��·
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {

    e[idx] = b; w[idx] = c, nxt[idx] = h[a], h[a] = idx++;
}

// ����ָ����·����Ϊ���������ǻ���Ȩ�ذ�������
// �ѵ����ڶ�dist[n]�����
bool spfa(void) {
    // �����滻Ϊstack, ��500��
    queue<int> q;
    // ȫ���ڵ������У����Խ������ͨ������
    for (int i = 1; i <= n; i++) {

        q.push(i);
        st[i] = true;
    }

    while (q.size()) {

        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = nxt[i]) {

            int j = e[i];

            // �жϸ�Ȩ�ķ�ʽ�ǣ����±�0��С�ľ��룬�ȼ���ֻ���¸�Ȩ
            if (dist[j] > dist[t] + w[i]) {

                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                // ����ۼƽڵ�������n˵��һ���㱻�����ο϶����ڻ�
                // ������m�����жϣ���n�����ݼ�����С��m�����Ի�������
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main(void) {

    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if (spfa()) puts("Yes");
    else puts("No");

    // ��� dist[]��Ϊ�˲鿴ÿһ���ڵ�����·�����������Ϊ0��˵��ֻ���¸�Ȩ���룬����������Ϊ��ֵ
    // for (int i = 1; i <= n; i++) printf("%d\n", dist[i]);

    return 0;
}

// TR�㷨��������Ϊͼ�۵Ĳ���֪ʶ
// https://en.wikipedia.org/wiki/Tarjan's_strongly_connected_components_algorithm
// https://oi-wiki.org/graph/scc/