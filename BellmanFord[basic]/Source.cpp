#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
// �ֱ�Ϊ�����ͱ���
const int N = 510, M = 10010;

int n, m, k;
// �ɶԵ����飬�洢��̾���ͱ�����̾���
int dist[N], backup[N];

struct Edge {

    // ���ɽṹ�壬�ֱ������㣬�յ��Ȩ��
    int a, b, w;

} edges[M];

// �ص��߼���1, ��δ���Ȩ��������2. ���������ԭ��
void bellman_ford(void) {

    // ����̾��������ʼ������1�ڵ��⣬ȫ����ʼ��Ϊ�������
    // ���⸺Ȩ��·��ԭ���Ǳ�����ö��ÿ����֮ǰ
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // �����ߵĸ�������Ҫ��������
    for (int i = 0; i < k; i++) {

        // �ڽ���ÿ��ƴ��֮ǰ�ȱ�����һ�μ��������
        memcpy(backup, dist, sizeof dist);

        for (int j = 0; j < m; j++) {

            // �ֱ���ȡ��Ԫ���е���㣬�յ��Ȩ��
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;

            // ������̾��룬ע��ڶ��������У�����Ȩ��Ӧ��ʹ�ñ������飬�������ݴ���
            // a, b�ǲ��м�����޸ĵģ�����û�п���ƴ�Ӳ�ͬ�߳��ȵĿ�����
            dist[b] = min(dist[b], backup[a] + w);

        }

    }

}

int main(void) {

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++) {

        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a, b, w };

    }

    bellman_ford();
    // ���500�㣬���10000�ߣ�������ֵΪ500W��ԶԶС��0x3f3f3f3f��һ��
    // ���·����ֵ��Ϊ += 500W,ԶԶС��21�ڼ���һ�룬����������2ֻ��Ϊ��ʹ���������
    if (dist[n] >= 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}
// �״�㣺�ṹ�����ͱ����Լ��ṹ���С��������̾���ƴ��ʱʹ�ñ������飻����ѭ��ʹ�ò�ͬ�ı�����Ϊָ��
// https://www.acwing.com/video/285/
// https://www.acwing.com/activity/content/code/content/48523/