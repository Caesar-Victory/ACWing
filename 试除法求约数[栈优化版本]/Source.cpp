#include <iostream>
#include <stack>

using namespace std;

void get_divide(int n) {

    stack<int> res;
    for (int i = 1; i <= n / i; i++) {

        if (n % i == 0) {

            // �ɶ�Լ���н�С��ֱ��������ϴ���ֱ�Ӵ洢
            cout << i << " ";
            if (i != n / i) res.push(n / i);
        }
    }

    // ����ö�ٳɶ�Լ���еĽ�С������С������˴���ջ�е����������ɴ�С������Ϊջ�ṹ�����С�������
    while (res.size()) {
        cout << res.top() << " ";
        res.pop();
    }
}

int main(void) {

    int n;
    scanf("%d", &n);
    while (n--) {

        int m;
        scanf("%d", &m);
        get_divide(m);
        puts("");
    }
}