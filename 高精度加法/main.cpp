#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;



// C = A + B；前面为数据类型，后面分别为函数和函数的形参，注意直接传入引用，避免拷贝增加性能损耗
vector<int> add(vector<int>& A, vector<int>& B) {
	// 生成合并数组
	vector<int> C;
	// 用于计算进位
	int t = 0;

	if (A.size() < B.size()) return add(B, A);

	for (int i = 0; i < A.size(); i++) {
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		// 注意此处为除法并且赋值
		t /= 10;
	}
	if (t) C.push_back(1);
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

	auto C = add(A, B);

	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	return 0;
}
