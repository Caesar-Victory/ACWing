#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void count_primes(int n) {

    for (int i = 2; i <= n; i++) {
        // �洢ÿһ��������ʹ��cnt�����������
        // cnt��Ϊprimesÿһ���������±�ͼ���������Ȼ��0��ʼ
        if (!st[i]) primes[cnt++] = i;
        // �Ե�ǰ����������i������Ϊģ����nȡģ����Ľ��������������Ϊj�±�����ޣ�ö����������
        // j�ڴ˴���Ϊ�±�[primes[j] <= n / i�ȼ��� primes[j] * i <= n, ��������ɾ���ĺ��� ]
        // n / i �����Ͻ���ʲô����Ϊprimes[j] <= n / i�� i ������ n �� ��С�������ı����� ���Ͻ���ľ�����С������
        for (int j = 0; primes[j] <= n / i; j++) {
            // ��ÿһ���� n / i֮ǰ������ �뵱ǰ��i��˵õ�������ɸ��
            st[primes[j] * i] = true;
            // �����ǰ���ܹ�������С����ȡģ����ֱ��ֹͣ����
            if (i % primes[j] == 0) break;
        }
    }
}

int main(void) {

    int n;
    scanf("%d", &n);
    count_primes(n);
    printf("%d\n", cnt);

    return 0;
}

// �ѵ㣺�ڲ�ѭ�����޵����壬������ĳ��������С����
// �״�㣺����ÿһ������ʱ����Ϊ n / i������ n % i, �����ѭ�����ܱ���������
// https://www.acwing.com/video/293/
// https://www.acwing.com/activity/content/code/content/49975/