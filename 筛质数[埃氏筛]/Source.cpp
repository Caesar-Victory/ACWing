#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void count_primes(int n) {

	// �������е���
	for (int i = 2; i <= n; i++) {
		// �ҵ�����
		if (!st[i]) primes[cnt++] = n;
		// ��Ƿ�ɾ�������������б���
		for (int j = i * 2; j <= n; j += i) st[j] = true;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	count_primes(n);
	printf("%d\n", cnt);
	return 0;
}

// �ѵ㣺��ⱶ��ɸѡ��ԭ��
// �״�㣺�ж�������˫�Ⱥţ���ֵ�õ��Ⱥţ������ѭ�����ܱ���������
// https://www.acwing.com/video/293/
// https://www.acwing.com/activity/content/code/content/49975/