#include <iostream>
#include <stack>

using namespace std;

void get_divide(int n) {

    stack<int> res;
    for (int i = 1; i <= n / i; i++) {

        if (n % i == 0) {

            // �ɶ�Լ���н�С��ֱ��������ϴ���ֱ�Ӵ洢��û������������ƽ�����������
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
// �״�㣺����ջ��ͷ�ļ�����ȡջ��Ԫ�غ�ɾ��ջ��Ԫ�أ������������ţ�
// https://www.acwing.com/video/294/
// https://www.acwing.com/activity/content/code/content/49976/