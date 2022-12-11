#include <cstdio>

using namespace std;

int n;

void get_primes(int n) {

    // ������ģ���ɶԳ��ֵĺ�����ÿ��ö��һ���н�С����һ����ʹ�ø��Ӷ�Ϊsqrt(n)
    for (int i = 2; i <= n / i; i++) {

        if (n % i == 0) {

            int s = 0;
            // ѭ���۳�������ݴ�
            while (n % i == 0) {

                n /= i;
                s += 1;

            }
            // ѭ����������������ݴκ�i����Ϊn�Ѿ���ģ�����Լ��۳�����ʱΪn��һ������
            printf("%d %d\n", i, s);
        }
    }
    // forѭ��������ʾ����nΪ������û�к��ʵĺ�����ֱ�ӷ����䱾���1����
    if (n > 1) printf("%d %d\n", n, 1);
    puts("");
}

int main(void) {

    scanf("%d", &n);
    while (n--) {

        int m;
        scanf("%d", &m);
        get_primes(m);
    }

    return 0;
}

// �״�㣺���׸�������߼���λ�ã���forѭ��������
// https://www.acwing.com/video/292/
// https://www.acwing.com/activity/content/code/content/49974/