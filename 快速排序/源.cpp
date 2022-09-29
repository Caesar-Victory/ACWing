#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ����,����ĳ��Ⱥ�����ռ����޾�����Ϊȫ�ֱ���
// ������� const ��̬�������η���N ʵ��ֵΪ double���ͣ�����������Ϊ int, �������Ͳ�һ��
const int N = 1e6 + 10;

// �βΣ�Ҳ�������ΪĬ��ֵ
int n;
int q[N];


void quick_sort(int q[], int l, int r) {

    if (l >= r) {
        return;
    }

    // ����ָ���ض�λ��ȡ��λ���е��ֵ�����ڲ�������
    int j = l - 1, k = r + 1, x = q[(l + r) >> 1];
    //int x = q[l], j = l - 1, k = r + 1;

    // ����whileѭ��������while��䣻��Χ������ָ����������Χ������������ָ��
    while (j < k) {

        do j++; while (q[j] < x);
        do k--; while (q[k] > x);

        if (j < k) {
            //swap(q[j], q[k]);
            int m = q[j];
            q[j] = q[k];
            q[k] = m;
        }
    }

    // �ݹ���ã�������Ϊ[l, r]���ֽ��Ϊ k & k + 1
    quick_sort(q, l, k);
    quick_sort(q, k + 1, r);

}

int main() {

    // ��ȡ�û���������鳤��
    scanf("%d", &n);

    // ��ȡ�û����������
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    // ����������ܵ����±�
    quick_sort(q, 0, n - 1);

    // �����ӡ�����������ÿһ��Ԫ��
    for (int i = 0; i < n; i++) {
        printf("%d", q[i]);
    }

    return 0;
}