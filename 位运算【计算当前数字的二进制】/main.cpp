#include <iostream>

using namespace std;

int main() {
	int n = 10;
	// ��Ҫ����֪��10��ʾΪ2��������λ
	for (int k = 3; k >= 0; k--) cout << (n >> k & 1) << endl;

	return 0;
}