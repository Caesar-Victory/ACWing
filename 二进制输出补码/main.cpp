#include <iostream>

using namespace std;


/// ����ԭ��������ڷ��� + 1, �൱������������ʱ��λ�����λ��һ��1�����ɸ�0</summary>
/// -x = 0 - x ���Զ���ԭ����˵������ȡ����һ<returns></returns>
int main() {

	int n = 10;
	unsigned int x = -n;

	for (int i = 31; i >= 0; i--) cout << ((-n) >> i & 1) << ' ';

	return 0;
}