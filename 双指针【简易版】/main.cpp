#include <iostream>
#include <string.h>

using namespace std;

int main() {

	// �����ַ�����ռ�
	char qstr[1000];
	// �������飬�������з�ֹͣ
	gets_s(qstr);

	// ��ȡ���鳤��
	int n = strlen(qstr);

	// ���ѭ������ÿһ��Ԫ�أ��൱����ָ��
	for (int i = 0; i < n; i++) {

		// ������ָ��
		int j = i;
		while (j < n && qstr[j] != ' ') j++;

		// ��ʼ�������
		for (int k = i; k < j; k++) cout << qstr[k];
		cout << endl;
		// ������ָ�룬��ȡ��һ�ε���
		i = j;
	}

	return 0;
}