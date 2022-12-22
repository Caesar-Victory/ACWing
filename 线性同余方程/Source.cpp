#include <iostream>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    // ԭ����Ϊ ax + b(y - a / b * x) = d
    y -= a / b * x;
    return d;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        // x��a��ϵ���� y�Ǵ���ϵ��
        int x, y;
        // d ָ����gcd(a, b)���Լ��
        int d = exgcd(a, m, x, y);
        // b ��������m ��ģ���еڶ�������
        if (b % d) puts("impossible");
        // �Խ�� % m ��Ϊ�˱�֤�����ֵ��2e9����[ʣ��ϵ]
        // m ��ͬ����  �������ѡȡ��ģ��
        else printf("%d\n", (LL)b / d * x % m);
    }
    return 0;
}


//  �״�㣺��չŷ������㷨�ڲ��ݹ�ʱ���ǽ���x, y����λ�ã���ŷ����ô���ʱ�������Ӧ����m��
// �����ģ����ĵڶ�������
//  https://www.acwing.com/video/303/
//  https://www.acwing.com/activity/content/code/content/50248/
//  ʣ��ϵ  https://baike.baidu.com/item/%E5%89%A9%E4%BD%99%E7%B3%BB/4644262
