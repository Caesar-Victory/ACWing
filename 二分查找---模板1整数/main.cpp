#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 100000;
// 分别为数组长度以及查询次数[函数调用次数]
int n, m;
int q[N];

int main()
{
	// 分别获取输入，数组长度和调用次数
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	// 以调用次数为条件开始循环
	while (m--)
	{
		// 先将待查找的数值输入程序
		int x;
		scanf("%d", &x);

		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			// 搜索区间左端点【左端点在二分的右半边】
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
				// 搜索区间右端点【右端点在二分的左半边】
				if (q[mid] <= x) l = mid;
				else r = mid - 1;
			}

			cout << l << endl;
		}
	}

	return 0;
}