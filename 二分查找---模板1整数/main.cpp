#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 100000;
// �ֱ�Ϊ���鳤���Լ���ѯ����[�������ô���]
int n, m;
int q[N];

int main()
{
	// �ֱ��ȡ���룬���鳤�Ⱥ͵��ô���
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	// �Ե��ô���Ϊ������ʼѭ��
	while (m--)
	{
		// �Ƚ������ҵ���ֵ�������
		int x;
		scanf("%d", &x);

		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			// ����������˵㡾��˵��ڶ��ֵ��Ұ�ߡ�
			if (q[mid] >= x) r = mid;
			else l = mid + 1;
		}

		if (q[l] != x) cout << "-1 -1" << endl;
		else
		{
			cout << l << ' ';

			int l = 0, r = n - 1;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				// ���������Ҷ˵㡾�Ҷ˵��ڶ��ֵ����ߡ�
				if (q[mid] <= x) l = mid;
				else r = mid - 1;
			}

			cout << l << endl;
		}
	}

	return 0;
}