#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;


const int mod = 1e9 + 7;

int main(void) {

    int n;
    scanf("%d", &n);
    unordered_map<int, int> primes;
    while (n--) {
        int m;
        scanf("%d", &m);
        for (int i = 2; i <= m / i; i++) {
            // ͬʱ��ȡ��������ָ��
            while (m % i == 0) {
                m /= i;
                primes[i]++;
            }
        }
        // ��һ��ָ��ֻ����������1����ֱ�ӶԸ���������
        if (m > 1) primes[m]++;
    }

    long long res = 1;
    // �����͹�ʽ��ѭ���۳ˣ���ÿ������ + 1��
    for (auto prime : primes) res = ((res * (prime.second + 1)) % mod);
    cout << res << endl;
    return 0;
}

// �״�㣺��ȡ������������ʱ������ö��ÿ�����֣�������������Ϊĳ������ƽ���������
// ��Ϊͬʱͳ��ָ����ָ��������ָ��Ϊ2
// // https://www.acwing.com/video/295/
// https://www.acwing.com/problem/content/872/