#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, int b) {

	vector<int> C;

	int carry = 0, i;
	// 顺序遍历，最小值在左边，因为被乘数 为一位数，所以每次仅需要对 10 取模
	for (int i = 0; i < A.size() || carry; i++) {
		if (i < A.size()) carry += A[i] * b;
		C.push_back(carry % 10);
		carry /= 10;
	}

	return C;
}

int main() {
	// 字符串存储较大数
	string a;
	// 被乘数直接以int存储
	int b;
	vector<int> A;

	cin >> a >> b;

	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

	vector<int> C = mul(A, b);

	// 边界检查，如果被除数/分母为零，则直接返回零
	if (b == 0) {
		printf("0");
	}
	else {
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}

	return 0;
}