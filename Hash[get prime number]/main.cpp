#include <iostream>
#include <cstdio>

using namespace std;

// �ú�����������һ������
int main(void) {

	// ���ѭ�����趨��㲢�ҿ�ʼ����
	for (int i = 100000; i++;) {
		// ���赱ǰ������������Ӧ�������俪���η��ڵ���������1�����������Ϊ���������������������˵����ǰ�� i �����������޸ı�ǲ��ҽ�������
		// ÿ�ε�ǰ�����ҿ����ڵ������������жϱ�ǣ����δ���������������ҽ���ѭ��
		bool flag = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i << endl; 
			break;
		}
	}

	return 0;
}