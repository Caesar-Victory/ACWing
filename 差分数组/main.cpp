#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m;

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

/// ���ٴ�������Ӽ�������ָ�����������Ҽ����Ա���ƽ�⣬����ǰ׺��������ͣ����ֻ��Ӱ���������˵��Ҳ����ֵ��
/// ѯ����������⡾���������ǰ׺�� s[n] = d[r] - [l - 1]��
int main() {

    scanf("%d%d", &n, &m);

    // ����ԭʼ����
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    // ��ԭʼ�������������
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        // �ض��������ֵ
        insert(l, r, c);
    }

    // ��ּ���
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

    // ���
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;

}