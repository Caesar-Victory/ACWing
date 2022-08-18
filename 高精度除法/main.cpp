#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �������������ã������������÷���ֵ��ֱ����ԭֵ�Ļ������޸ģ��ֲ�������ͬ���޸ĵ�ȫ�ֱ���
vector<int> div(vector<int> &A, int b, int &r) {

	vector<int> C;
	r = 0;

	// �����Ӹ�λ��ʼ���㣬��˵��������ȡֵ
	for (int i = A.size() - 1; i >= 0; i--) {
		// ��һ������������ۼӵ�������Ҫ����10�����һ����λ
		r = r * 10 + A[i];
		// ������ÿһ��λ�洢�����̣���������뵽��һ�εļ���
		C.push_back(r / b);
		// �����������һ�����㣬������Ҫȡģ�͸�ֵ����
		r %= b;
	}

	// ��ת�ַ����������ļ������ʹ洢˳���෴��ÿһ�δ洢������β��׷�ӣ����¸�λ����ߣ�
	reverse(C.begin(), C.end());

	// ��ͬλ������������ǰ���������������Ҫȥ��
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

	// ���ֵ��ͬʱ������Ҫ�������
	cout << endl << r << endl;

	return 0;

}