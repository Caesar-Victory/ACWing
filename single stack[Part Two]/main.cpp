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

		// 根据条件【栈不为空以及栈顶元素大于输入的值】循环出栈
		while (top && stack[top] >= x) top--;

		// 循环出栈后，若栈不为空，则栈顶元素必为离现在元素最近最小的值
		if (top) printf("%d ", stack[top]);
		// 否则输出-1
		else printf("-1 ");

		// 对输入元素入栈，为什么不先入栈后出栈以及判断出栈操作后栈顶元素呢？因为会导致刚入栈就被删除，无法参考整个输入：N个元素
		stack[++top] = x;
	}

	return 0;
}