#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;
int n;
int stack[N], top;

int main(void) {

	scanf("%d", &n);

	while (n--) {

		int x;
		scanf("%d", &x);

		// ����������ջ��Ϊ���Լ�ջ��Ԫ�ش��������ֵ��ѭ����ջ
		while (top && stack[top] >= x) top--;

		// ѭ����ջ����ջ��Ϊ�գ���ջ��Ԫ�ر�Ϊ������Ԫ�������С��ֵ
		if (top) printf("%d ", stack[top]);
		// �������-1
		else printf("-1 ");

		// ������Ԫ����ջ��Ϊʲô������ջ���ջ�Լ��жϳ�ջ������ջ��Ԫ���أ���Ϊ�ᵼ�¸���ջ�ͱ�ɾ�����޷��ο��������룺N��Ԫ��
		stack[++top] = x;
	}

	return 0;
}