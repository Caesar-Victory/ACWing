#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int primes[N], euler[N], cnt;
bool st[N];

void get_euler(int n) {
    // ��1���ʵ���������������ָ�����������߶�����ֵ����Լ��Ϊ1���˸��Ӵ��ŵ�������
    // ����һ��
    // �״�㣺λ��1���״�дΪi
    euler[1] = 1;
    // �״�㣬�������������С����2
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            // ���һ������������������ŷ������Ϊ������ - 1
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                // ���������С����primes[j]��i��������ŷ����������primes[j]����[i��ŷ������]
                euler[primes[j] * i] = primes[j] * euler[i];
                break;
            }
            // ���primes[j]����i������������ô����ŷ����������[primes[j] - 1]����[i��ŷ������]
            euler[primes[j] * i] = (primes[j] - 1) * euler[i];
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    LL res = 0;
    get_euler(n);
    for (int i = 1; i <= n; i++) res += euler[i];
    cout << res << endl;
    return 0;
}

// https://www.acwing.com/video/28/
// https://www.acwing.com/activity/content/code/content/49995/