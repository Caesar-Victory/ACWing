#include <iostream>
//#define lowbit(x) ((x) & (-x))

using namespace std;

// ʼ��������ҵ��󣬵�һ��1�����ұߵ�����0
int lowbit(int x) {
	// x & (~x + 1)[����]
	return x & (-x);
}

int main() {

	int n;
	cin >> n;

	while (n--) {

		int x;
		cin >> x;

		int res = 0;
		// �� x = 10Ϊ���������Ʊ�ʾΪ 1010����һ�μ�ȥ10Ҳ����2���ڶ��μ�ȥ1000,Ҳ����8
		while (x) x -= lowbit(x), res++;

		cout << res << ' ';
	}

	return 0;
}