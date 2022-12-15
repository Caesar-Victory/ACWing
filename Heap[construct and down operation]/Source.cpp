#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
// @size: ��ǰ���ж��ٸ�Ԫ��
// �������������Դ洢�ģ���ô�±�С�ľ��Ǹ��ڵ㣬�±��ľ��Ƕ��ӽڵ�
int h[N], scale;

void down(int u) {
    // @t: ��ʾ�������е���Сֵ��
    // �˲����ǽ�λ�� u �������������Ҽ���ԭ����
    int t = u;
    // ��������ӣ���������ӵ�ֵ����Ҫ�ƶ��Ľڵ�С
    if (u * 2 <= scale && h[u * 2] < h[t]) t = u * 2;
    // �����Ҷ��ӣ��Ҷ��ӵ�ֵ����Ҫ�ƶ��Ľڵ�С
    if (u * 2 + 1 <= scale && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    // �������˼��ÿ�ҵ�һ���µ����꡾���ҽڵ㡿���ͽ���������ֵ���ҵ�����ֱ������Ѷ���
    // �״�㣺����дΪwhile���
    if (u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u) {

    // ���ڵ�ȵ�ǰ����㻹Ҫ�����任��ȥ
    while (u / 2 && h[u / 2] > h[u]) {
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main(void) {

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);

    // ����֮ǰ�����Ĳ�����
    // ���ѵ��ݻ�����Ϊ�ڵ��������Ϊ���ǽ��������ĩβ��ʼdown()ÿһ��Ԫ��
    scale = n;

    for (int i = n / 2; i; i--) down(i);

    while (m--) {
        printf("%d ", h[1]);
        // ����β�ͽڵ�ͶѶ��ڵ�
        h[1] = h[scale];
        // ��ģ��һ��ζ��ɾ��
        scale--;
        // �Ѷ�Ԫ�ر����¸�ֵ���������ҽڵ�Ĵ�С��ϵ���ܷ����仯���ʴ�down()����һ��
        // �״�� 1 ���״�дΪ i
        down(1);
    }

    return 0;
}

// https://www.acwing.com/video/263/
// https://www.acwing.com/activity/content/code/content/45296/