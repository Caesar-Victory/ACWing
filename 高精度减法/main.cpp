#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {
	// �ȸ������鳤���жϴ�С
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

	// ��ֵ���ҵ��󣬼�������ҡ���λ����λ��
	for (int i = 0, car = 0; i < A.size(); i++) {

		car = A[i] - car;

		if (i < B.size()) car -= B[i];
		// Ԥ��λ��Ȼ�����car��B[i]����Ľ���ж��Ƿ��λ
		C.push_back((car + 10) % 10);

		if (car < 0) car = 1;
		else car = 0;
	}

	while (C.size() > 1 && C.back() == 0) C.pop_back();

	return C;
}


int main() {
	// ̫�������ַ����洢
	string a, b;
	// ���Զ��������鳤�ȣ��������ָ��
	vector<int> A, B;
	// a = "123456"
	cin >> a >> b;
	// ���ַ��������������������,ע�����޼�һ����������������ʱ����Խ��
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  // A = {6, 5, 4, 3, 2, 1}
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	// ���Сֱ�����㲢�������С�����򽫴�����������Ĳ����Ի�λ�ã����������ʱ�����һ������
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