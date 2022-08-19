#include <iostream>

using namespace std;

int n;
const int N = 1e5 + 10;
int a[N], s[N];

// 146的数据范围内，用cin , cout更快；
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	int res = 0;

	for (int i = 0, j = 0; i < n; i++) {

		// 下标作为hash的键， 下标对应的值作为hash的值
		s[a[i]]++;
		while (s[a[i]] > 1) {

			// 清除数组中元素仅出现过一次的元素，同时清除重复数字，简而言之，遇到重复时，使得快慢指针相遇
			s[a[j]]--;
			j++;
		}

		// 如果书中中元素唯一，该语句负责不断计算快慢指针的距离差
		// 加一是因为下标从0开始，而人类计数从1开始
		res = max(res, i - j + 1);
	}

	cout << res << endl;

	return 0;
}