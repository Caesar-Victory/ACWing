#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    // ���� b Ϊ��С��
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}

// �������������Լ���������н�С����������������������Լ��
// https://www.acwing.com/video/297/
// https://zh.wikipedia.org/wiki/%E8%BC%BE%E8%BD%89%E7%9B%B8%E9%99%A4%E6%B3%95
// https://www.acwing.com/activity/content/code/content/49986/