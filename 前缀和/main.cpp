#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], s[N];
int n, m;

int main() {

	// �ֱ��ȡ����ĳ��ȣ��Ͳ�ѯ�Ĵ���
	scanf("%d%d", &n, &m);

	// ���������ֵ��������
	for (int i = 1; i <= n; i++) scanf("%d", &q[i]);

	// ע���ۼӵķ������ǵ�ǰ�������һ��λ���Ӧ��ֵ�������ۼӶ���ĵ�ǰλ��
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + q[i];

	while (m--) {

		int l, r;
		scanf("%d%d", &l, &r);
		// ��һ����Ϊ������ۼӾ���1��ʼ[��������Խ��]
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}