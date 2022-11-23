#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

// �����е���ֵ���չ�ϣ�ԣ����룬�ڵ��Ŵ洢
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n, m;
int h[N], w[N], e[N], nxt[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {

    e[idx] = b, w[idx] = c, nxt[idx] = h[a], h[a] = idx++;

}



int dijkstra(void) {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // ���ȶ�����ÿ��Ԫ�ض���pair����
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    // ֵΪ�㣬���Ϊ1
    heap.push({ 0, 1 });

    while (heap.size()) {

        // �������ȶ����ж�ȡ�Ѷ�Ԫ�أ�Ȼ��ɾ��
        auto t = heap.top();
        heap.pop();

        // �ֱ�ͨ�������������ڵ��ź;���
        int ver = t.second, distance = t.first;

        // �ҵ�����Сֵ������֮ǰ�Ѿ�ȷ�����ˣ�ע������ѡȡ�Ķ����±꡿�ǽڵ�
        // ȥ�ز���
        if (st[ver]) continue;
        // ���ҽ���̾�����Ϊ��ȷ������δ��뿴�������Ƿϻ���ȥ�����ֻ�TLE��
        st[ver] = true;

        // ͨ���ֲ����� ver �ڵ��Ŵ�������
        // �������е�ĳ��߾��Ǳ������бߣ������������ԡ�
        for (int i = h[ver]; i != -1; i = nxt[i]) {

            // ȡ��ÿһ���ڵ���
            int j = e[i];

            // ��ǰ�ڵ��ŵľ��룬�Ƿ���ڶ����д洢�ľ���  + ��Ȩ��
            if (dist[j] > distance + w[i]) {

                // ���¸�ֵ���ٴη������
                dist[j] = distance + w[i];
                heap.push({ dist[j], j });
            }

        }
    }

    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];

}

int main(void) {

    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {

        int a, b, c;
        cin >> a >> b >> c;

        add(a, b, c);

    }

    int t = dijkstra();

    printf("%d\n", t);

    return 0;
}