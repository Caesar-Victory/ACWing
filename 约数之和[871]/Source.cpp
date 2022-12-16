#include <iostream>
#include <unordered_map>


using namespace std;

typedef long long LL;

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
                // ��дΪn
                m /= i;
                primes[i]++;
            }
        }
        // ��һ��ָ��ֻ����������1����ֱ�ӶԸ���������
        if (m > 1) primes[m]++;
    };

    LL res = 1;
    for (auto prime : primes) {
        int p = prime.first, a = prime.second;
        LL t = 1;
        // �ؾ����㷨
        // �����е�����ȡģ��Ϊ�˷�ֹ�м���������ֵ���
        while (a--) t = (t * p + 1) % mod;
        res = res * t % mod;


    }
    cout << res << endl;
    return 0;
}

// �״�㣺��ȡ������������ʱ������ö��ÿ�����֣�������������Ϊĳ������ƽ���������
// �״�㣬��ȡn����ʱ��ÿһ��������Ϊ���޼�m,����n
// ��Ϊͬʱͳ��ָ����ָ��������ָ��Ϊ2
// // https://www.acwing.com/video/295/
// https://www.acwing.com/problem/content/872/