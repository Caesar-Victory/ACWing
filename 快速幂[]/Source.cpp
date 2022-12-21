#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int quickmi(int a, int b, int p) {
    // ��������������0��1������κ�����������mod1�Ľ����Ϊ0����Ϊ��Ϊ1����������û������
    // p = 1, b = 0
    int res = 1 % p;
    while (b) {
        // ���k�Ķ����Ʊ�ĩβΪ1����ֱ�����
        if (b & 1 == 1) res = (LL)res * a % p;
        // K����һλ��ɾ��ĩβ
        b >>= 1;
        // (x * y) % p = (x % p * y % p) % p;
        // ÿ����һ��a,�൱���ݴμ�1��Ҳ���൱���ݴβ���ÿ�μ�1��Ҳ���� + 2 ^ 0
        // ��ָ���Ķ����Ʊ�ʾ����һ������������ƽ��Ҫ�����ǣ�������λ��Ϊ1����ֱ���÷���ֵ���Ե���
        // ��λ��Ϊ0ʱ���������´��룬���ݴ���2���ݴμ�1
        // ˭��Ϊ�������Ͷ�˭���ݴ�+1
        // �״�㣬���׽���ֵдΪres
        a = (LL)a * a % p;
    }
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%d\n", quickmi(a, b, p));
    }
    return 0;
}

// https://www.acwing.com/activity/content/code/content/50237/
// https://www.acwing.com/video/300/
// https://oi-wiki.org/math/binary-exponentiation/
// https://zh.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E6%B1%82%E5%B9%82