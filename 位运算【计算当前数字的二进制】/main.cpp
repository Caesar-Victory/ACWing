#include <iostream>

using namespace std;

int main() {
	int n = 10;
	// 需要事先知道10表示为2进制有四位
	for (int k = 3; k >= 0; k--) cout << (n >> k & 1) << endl;

	return 0;
}