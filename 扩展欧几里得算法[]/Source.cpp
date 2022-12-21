#include <iostream>

using namespace std;

// �����ã���Ҫ���ؼ�����x, y
int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    // ����x, y��λ��,ʹ��������a,b�Ĳ���λ�ö�Ӧ
    int d = exgcd(b, a % b, y, x);
    // ��������Ľ�������㵱ǰ����Ľ�����ݹ����������y
    y -= a / b * x;
    return d;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}
// �״�㣺����x, y�Ǵ����ã�д����&����
// �������Ҫ�������������ñ����������������ڼ���yֵ
// https://www.acwing.com/video/302/
// https://www.acwing.com/activity/content/code/content/50245/