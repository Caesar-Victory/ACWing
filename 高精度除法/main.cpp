#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 传入余数的引用，这样不必设置返回值，直接在原值的基础上修改，局部函数会同步修改到全局变量
vector<int> div(vector<int> &A, int b, int &r) {

	vector<int> C;
	r = 0;

	// 除法从高位开始计算，因此倒序从数组取值
	for (int i = A.size() - 1; i >= 0; i--) {
		// 上一次运算的余数累加到本次需要乘以10，相差一个数位
		r = r * 10 + A[i];
		// 除法的每一个位存储的是商，商无需加入到下一次的计算
		C.push_back(r / b);
		// 余数会加入下一次运算，所以需要取模和赋值运算
		r %= b;
	}

	// 翻转字符串，除法的计算结果和存储顺序相反（每一次存储都是在尾部追加，导致高位在左边）
	reverse(C.begin(), C.end());

	// 相同位数相除，会存在前导零的情况，因此需要去除
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