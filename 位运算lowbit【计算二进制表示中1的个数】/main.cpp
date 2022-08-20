#include <iostream>
//#define lowbit(x) ((x) & (-x))

using namespace std;

// 始终输出从右到左，第一个1及其右边的所有0
int lowbit(int x) {
	// x & (~x + 1)[补码]
	return x & (-x);
}

int main() {

	int n;
	cin >> n;

	while (n--) {

		int x;
		cin >> x;

		int res = 0;
		// 以 x = 10为例，二进制表示为 1010，第一次减去10也就是2，第二次减去1000,也就是8
		while (x) x -= lowbit(x), res++;

		cout << res << ' ';
	}

	return 0;
}