#include <iostream>

using namespace std;

int n;
const int N = 1e5 + 10;
int a[N], s[N];

// 146�����ݷ�Χ�ڣ���cin , cout���죻
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	int res = 0;

	for (int i = 0, j = 0; i < n; i++) {

		// �±���Ϊhash�ļ��� �±��Ӧ��ֵ��Ϊhash��ֵ
		s[a[i]]++;
		while (s[a[i]] > 1) {

			// ���������Ԫ�ؽ����ֹ�һ�ε�Ԫ�أ�ͬʱ����ظ����֣������֮�������ظ�ʱ��ʹ�ÿ���ָ������
			s[a[j]]--;
			j++;
		}

		// ���������Ԫ��Ψһ������为�𲻶ϼ������ָ��ľ����
		// ��һ����Ϊ�±��0��ʼ�������������1��ʼ
		res = max(res, i - j + 1);
	}

	cout << res << endl;

	return 0;
}