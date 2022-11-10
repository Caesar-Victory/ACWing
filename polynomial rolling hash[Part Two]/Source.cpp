#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

// ���������͵ı�ʶ�����¶��� ��Ϊ�˽�ʡ�ô����ʱ��
typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

ULL h[N], p[N];
int n, m;
// ������洢ÿһ���������ĸ
char str[N];

ULL get(int l, int r) {

    // �൱�ڹ�ʽ h[n] - h[n-1] * p ^ (l - r + 1)
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(void) {

    scanf("%d%d%s", &n, &m, 1 + str);

    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        // p[] ����洢����Pֵ�Ĵη���λ���ݴ�
        p[i] = p[i - 1] * P;
        // h[] ����洢�����ַ���ǰ׺��ϣֵ��ֱ�� + asc����
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}