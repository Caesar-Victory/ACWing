#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;



// C = A + B��ǰ��Ϊ�������ͣ�����ֱ�Ϊ�����ͺ������βΣ�ע��ֱ�Ӵ������ã����⿽�������������
vector<int> add(vector<int>& A, vector<int>& B) {
	// ���ɺϲ�����
	vector<int> C;
	// ���ڼ����λ
	int t = 0;

	if (A.size() < B.size()) return add(B, A);

	for (int i = 0; i < A.size(); i++) {
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		// ע��˴�Ϊ�������Ҹ�ֵ
		t /= 10;
	}
	if (t) C.push_back(1);
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

	auto C = add(A, B);

	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	return 0;
}
