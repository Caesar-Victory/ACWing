#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], nxt[M], idx;
int match[N];
bool st[N];

int find(int x) {

    // ö��������Ҫ׷�������Ů����
    for (int i = h[x]; i != -1; i = nxt[i]) {

        int j = e[i];

        if (!st[j]) {
            st[j] = true;
            // Ů����û�ж��󣬻����ǿ������������ѵ�ǽ��
            // ���Ҫȥ�ݹ�Ů���ӵĶ�����������Ķ�λŮ���ӣ�Ҳ��������Ϊ��̥����������������ѻ��б�̥
            // ��ռɽΪ����
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;
}

int main(void) {

    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m--) {

        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    // ͳ�ƿ�ƥ�����������
    int res = 0;

    // �������ÿһ���к��ӣ���ΪMatch����洢����Ů�����ǵ�������
    for (int i = 0; i <= n1; i++) {

        // ��ֹѭ���ݹ飬�ٶ�����������ѡ��ÿһλŮ���������Ҷ���
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }

    printf("%d\n", res);

    return 0;
}