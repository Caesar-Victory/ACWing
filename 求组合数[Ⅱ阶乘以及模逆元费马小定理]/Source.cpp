#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, mod = 1e9 + 7;;

int fact[N], infact[N];

int qmi(int a, int k, int p) {
    // �������ӣ���ʼ��Ϊ1
    int res = 1;
    // k ÿ����λ����ķ�ʽ����2
    while (k) {
        // �����ǰ��ĩβΪ1��˵����λ��ѡȡ��������res�������һ�ε�ֵ�۳�
        if (k & 1) res = (LL)res * a % p;
        // ����� a ƽ����ȡģ�����Ǳ��������� 101 �������λ���ܹ���ʱ������ 2 ��
        a = (LL)a * a % p;
        // k ÿ����λ����ķ�ʽ����2
        k >>= 1;
    }
    return res;
}

int main(void) {

    // ����������еĽϴ����֣�Ҫʹ�õ���ʽ������׳�
    // ��������еĽ�С���֣���ʹ�õ���ʽ����׳�ʱ����Ҫ����������ݣ�����ӳ���ת��Ϊ����
    // ���߶���Ҫ�ڼ�������п� long long �Լ�ȡģ�����ڵ�ǰ�� i �� ��ָ��Ϊ mod - 2, ģ��Ϊmod
    // ����С����
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        // infact[i] = (LL)qmi(fact[i], mod - 2, mod) % mod; //ͨ��fact��infact
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        // ����Ϲ�ʽ�Ļ����ϣ����ڷ�����׳ˣ�����������н�Сֵ����Ԫ���Լ����������ֵ����Ԫ
        // ÿ���γ˷����㣬ȡģһ��
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }

    return 0;
}

// �״�㣬��������ָ��kÿ�γ��� 2 ��д����λ��һλ������д�Ⱥ�
// �׳����㣬���������1������0
// ����С���� https://zh.wikipedia.org/wiki/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86
// https://www.acwing.com/video/307/
// https://www.acwing.com/activity/content/code/content/53394/