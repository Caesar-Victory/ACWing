#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        int res = a;
        for (int i = 2; i <= a / i; i++) {
            if (a % i == 0) {
                // res = res * (1 - 1 / a);
                // �ȼ�����������������ת��Ϊlong long ���;Ϳ��Բ���������˳��
                // es = 1LL * res * (a-1) / a;
                // ������� Snǰ n ���
                res = res / i * (i - 1);
                while (a % i == 0) a /= i;
            }
        }
        // �״�㣬�����Ǵ�����������1�Ľϴ���������˱ض���forѭ��֮��
        if (a > 1) res = res / a * (a - 1);
        cout << res << endl;
    }
    return 0;
}

// https://www.acwing.com/video/298/
// https://www.acwing.com/activity/content/code/content/49992/