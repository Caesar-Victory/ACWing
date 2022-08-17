#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 传入余数的引用，这样不必设置返回值，直接在原值的基础上修改，局部函数会同步修改到全局变量
vector<int> div(vector<int> &A, int b, int &r) {

	vector<int> C;
	r = 0;

	// 遍历的上限是A数组的长度 - 1，而非C数组
	for (int i = A.size() - 1; i >= 0; i--) {
		// 当前的余数是下一个数位的十倍
		r = r * 10 + A[i];
		// C数组存储的是商
		C.push_back(r / b);
		r %= b;
	}

	// 翻转字符串
	reverse(C.begin(), C.end());

	while (C.size() > 1 && C.back() == 0) C.pop_back();


	return C;
}

int main() {
	string a;
	int b;

	vector<int> A;

	cin >> a >> b;

	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

	int r;
	auto C = div(A, b, r);

	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

	// 输出值的同时，还需要输出余数
	cout << endl << r << endl;

	return 0;

}