#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, int b) {

	vector<int> C;

	int carry = 0, i;
	// ˳���������Сֵ����ߣ���Ϊ������ Ϊһλ��������ÿ�ν���Ҫ�� 10 ȡģ
	for (int i = 0; i < A.size() || carry; i++) {
		if (i < A.size()) carry += A[i] * b;
		C.push_back(carry % 10);
		carry /= 10;
	}

	return C;
}

int main() {
	// �ַ����洢�ϴ���
	string a;
	// ������ֱ����int�洢
	int b;
	vector<int> A;

	cin >> a >> b;

	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

	vector<int> C = mul(A, b);

	// �߽��飬���������/��ĸΪ�㣬��ֱ�ӷ�����
	if (b == 0) {
		printf("0");
	}
	else {
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}

	return 0;
}