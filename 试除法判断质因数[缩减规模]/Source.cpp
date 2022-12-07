#include <cstdio>

using namespace std;

bool primes(int x) {
    // �߽��飬С��2һ��û������
    if (x < 2) return false;
    // ��Ϊ����Ҫ�ж����������һ���� i Ϊ x �ĺ�������ô  x / i Ҳ�� x �ĺ���
    // �������ǳɶԳ��֣����ڽ���Ҫ�ж��Ƿ�Ϊ�������������ֻ��Ҫö�� x/i�Ĳ��ּ���
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int main(void) {

    int n;
    scanf("%d", &n);
    while (n--) {

        int m;
        scanf("%d", &m);
        if (primes(m)) puts("Yes");
        else puts("No");
    }
    return 0;
}