#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {
	// 先根据数组长度判断大小
	if (A.size() != B.size()) return A.size() > B.size();
	int i;
	for (int i = A.size() - 1; i >= 0; i--) {
		if (A[i] != B[i]) {
			return A[i] > B[i];
		}
	}
	return true;
}

vector<int> sub(vector<int>& A, vector<int>& B) {

	vector<int> C;

	// 传值从右到左，计算从左到右【高位到低位】
	for (int i = 0, car = 0; i < A.size(); i++) {

		car = A[i] - car;

		if (i < B.size()) car -= B[i];
		// 预进位，然后根据car与B[i]计算的结果判断是否借位
		C.push_back((car + 10) % 10);

		if (car < 0) car = 1;
		else car = 0;
	}

	while (C.size() > 1 && C.back() == 0) C.pop_back();

	return C;
}


int main() {
	// 太长了用字符串存储
	string a, b;
	// 可自动计算数组长度，无须另加指针
	vector<int> A, B;
	// a = "123456"
	cin >> a >> b;
	// 将字符数组逆序读入两个数组,注意上限减一，，避免容器访问时数组越界
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  // A = {6, 5, 4, 3, 2, 1}
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	// 大减小直接运算并且输出，小减大则将传入减法函数的参数对换位置，并且在输出时先输出一个负号
	if (cmp(A, B)) {
		auto C = sub(A, B);

		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}
	else {

		auto C = sub(B, A);

		printf("-");

		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}

	return 0;
}