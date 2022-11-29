#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int q[N];


int quick_select(int l, int r, int k) {

    if (l == r) return q[l];

    int x = q[l], i = l - 1, j = r + 1;

    while (i < j) {

        do ++i; while (q[i] < x);
        do --j; while (q[j] > x);

        if (i < j) swap(q[i], q[j]);
    }
    // L����߽�㣬JΪ����ָ�룬�Ǳ�㣬Ҳ������������ޣ�+1��Ϊ�˽�����תΪλ��
    // S1��������������Ѿ������Ԫ�ظ���
    int s1 = j - l + 1;
    // ����ѡ�񲢲��ݹ����˫�ߣ�����ֻ�ݹ����һ�ߵ�Ԫ���м���Ѱ��
    if (k <= s1) return quick_select(l, j, k);
    return quick_select(j + 1, r, k - s1);
}

int main(void) {

    cin >> n >> k;

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    cout << quick_select(0, n - 1, k) << endl;

    return 0;

}
