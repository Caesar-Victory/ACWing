#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int h[N];

// ��������ҵ�ֵ��h[] ���鵱�У�ֱ�ӷ���λ�򣬲����򷵻��ʺ�������λ��
int find(int x) {

    int k = (x % N + N) % N;
    // �����ǰλ��洢��ֵ������Ĭ��ֵ������Ҳ�������Ǵ�Ѱ�ҵ�ֵ����һ·����Ѱ��
    while (h[k] != null && h[k] != x) {
        k++;
        // ���������һ�γ���ΪN�ı���֮�󣬴�ͷ��ʼ����
        if (k == N) k = 0;
    }
    return k;
}

int main(void) {

    int n;
    scanf("%d", &n);

    // int ���ĸ��ֽڣ���������3f�ᱻ����Ϊ4�εĽ������ 0x3f3f3f3f
    memset(h, 0x3f, sizeof h);

    while (n--) {

        int x;
        char op[2];
        scanf("%s%d", op, &x);
        // ������ h[] �������е������ҵ�ֵ
        int k = find(x);
        // ������ֵ�������ڣ��򽫵�ǰλ��ֵΪ x
        if (*op == 'I') h[k] = x;
        else {
            // ������ֵ�Ѿ��洢�� h[] ���鵱�У����Ҳ�Ϊ��
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}