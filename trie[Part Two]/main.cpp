#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

// son: 相当于开了一个数组，每遇到一个字符就开一个子数组
int son[N][26], cnt[N], idx;

void insert(char str[])
{
	// 为Trie遍历主数组
	int p = 0;

	// str[-1] = '\0'
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])
		{
			// 只要插入必移动一次指针，这次移动传值，作为Trie一维坐标的方向
			// 所以同时会移动son[idx]
			son[p][u] = ++idx;
		}
		p = son[p][u];
	}
	// 插入元素最后一个字母的计数加一
	cnt[p]++;
}

int query(char str[])
// 逻辑与插入大致相同，只不过找不到就返回0，如果有则返回单词最后一个字母的计数
{
	int p = 0;

	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		
		if (!son[p][u]) 
		{
			return 0;
		}
		else
		{
			p = son[p][u];
		}
	}

	return cnt[p];
}

int main() 
{

	int n;
	scanf("%d", &n);

	while (n--)
	{
		// 是防止前后出现多余空格下个数据读入不准确
		char op[2];
		char str[N];
		// 这里输入为什么参数不是 &op, &str
		scanf("%s%s", op, str);


		if (op[0] == 'I') insert(str);
		else printf("%d\n", query(str));
	}

	return 0;
}