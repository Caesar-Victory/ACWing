#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

// ����ͼ�������Ĵ洢�ռ�
const int N = 1e5 + 10, M = 2 * 1e5 + 10;

using namespace std;

int n, m;
int h[N], e[M], nxt[M], idx;
int color[N];

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {

    // ��¼��ǰ�����ɫ
    color[u] = c;
    // ����һ�µ�ǰ��������ڵ�
    for (int i = h[u]; i != -1; i = nxt[i]) {

        // �� j �洢��ǰ��ı��
        int j = e[i];
        // ��δȾɫ��Ĭ��Ϊ0���Ȳ���1��Ҳ����2
        if (!color[j]) {
            // 3 - c�Ϳ���ʵ�� 1 ---> 2 / 2 ---> 1
            // DFS������룬����֪�ϲ���ɫΪc������£����²�ͨ��3-cת������
            // 3- c ����ת����ɫ����һ��ֻ��1��2������ɫ��ͼ�У����Դﵽһ�ַǴ˼��˵�Ч��
            if (!dfs(j, 3 - c)) return false;
            // ����ͬɫ�򷵻�False
        }
        // �ͺ�����Ķ�����ƣ�һ����ɫ�ڵ����������ɫ���ӽڵ㣻���仰˵�����ӽڵ����ɫ��һ��
        // �����ڴ����Ի����Ի��Ķ������Լ�ָ���Լ�����ô��Ȼ���������յ����ɫ��ͬ
        else if (color[j] == c) return false;
    }

    return true;
}

int main(void) {

    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m--) {

        int a, b;
        scanf("%d%d", &a, &b);
        // �ڽӱ�洢����ͼ���Ǵ洢����
        // �ڽӾ���洢ͼ���ǽ�������洢���Σ����� g[a][b] = g[b][a] = min(g[a][b], c)
        add(a, b), add(b, a);
    }

    // ���Ⱦɫ�����е�ì��
    bool flag = true;

    // ���սڵ㿪ʼȾɫ���������нڵ��Ƿ�ֹ�еĵ�֮�䲻��ͨ
    for (int i = 1; i <= n; i++) {

        // ��ǰ��û�б�Ⱦɫ
        if (!color[i]) {

            // ����ֵΪFalse ��ì�ܷ���������ֹͣȾɫ
            // Ҳ�������Ϊ��һ����ɫΪ1
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }

    if (flag) puts("Yes");
    else puts("No");

    return 0;
}

// https://www.acwing.com/video/289/
// https://www.acwing.com/activity/content/code/content/48778/