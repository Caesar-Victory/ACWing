#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int N = 7;
int n;
int path[N];
bool st[N];

void dfs(int u) {

    // �ݹ�����������ǣ����ڱ�������ַ��������ȵı��� u �� �����������
    if (u == n) {
        for (int i = 0; i < n; i++) printf("%d ", path[i]);
        puts(" ");
        return;
    }

    // ö�ٵ���ֵ�� [1, n]
    // �ݹ�ǰ����Ҫ�޸����ֵ�״̬��ʹ�ò���ֵ��Ǹ������Ƿ�ʹ�� --- �ָ��ֳ�
    for (int i = 1; i <= n; i++) {
        // st[]  ���鰴��ֵ����Ƿ��ù�
        // path[] ���鰴���±� ��ǳ���Ϊ n ���飬�Ǹ�λ���ϴ洢���Ǹ�ֵ
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            // �ָ��ֳ�: path[u] ÿ��ֻ�洢һ��ֵ����Ϊ���ݻᷴ����д����˲���ʹ�� path[u] = 0 ��
            st[i] = false;
        }
    }
}

int main(void) {

    cin >> n;
    dfs(0);
    return 0;
}