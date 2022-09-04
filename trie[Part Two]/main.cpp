#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

// son: �൱�ڿ���һ�����飬ÿ����һ���ַ��Ϳ�һ��������
int son[N][26], cnt[N], idx;

void insert(char str[])
{
	// ΪTrie����������
	int p = 0;

	// str[-1] = '\0'
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])
		{
			// ֻҪ������ƶ�һ��ָ�룬����ƶ���ֵ����ΪTrieһά����ķ���
			// ����ͬʱ���ƶ�son[idx]
			son[p][u] = ++idx;
		}
		p = son[p][u];
	}
	// ����Ԫ�����һ����ĸ�ļ�����һ
	cnt[p]++;
}

int query(char str[])
// �߼�����������ͬ��ֻ�����Ҳ����ͷ���0��������򷵻ص������һ����ĸ�ļ���
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
		// �Ƿ�ֹǰ����ֶ���ո��¸����ݶ��벻׼ȷ
		char op[2];
		char str[N];
		// ��������Ϊʲô�������� &op, &str
		scanf("%s%s", op, str);


		if (op[0] == 'I') insert(str);
		else printf("%d\n", query(str));
	}

	return 0;
}