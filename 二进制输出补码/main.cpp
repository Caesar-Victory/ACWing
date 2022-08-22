#include <iostream>

using namespace std;


/// 补码原理：补码等于反码 + 1, 相当于我们做减法时借位，最高位补一个1，若干个0</summary>
/// -x = 0 - x 所以对于原数来说，等于取反加一<returns></returns>
int main() {

	int n = 10;
	unsigned int x = -n;

	for (int i = 31; i >= 0; i--) cout << ((-n) >> i & 1) << ' ';

	return 0;
}