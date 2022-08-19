#include <iostream>
#include <string.h>

using namespace std;

int main() {

	// 生成字符数组空间
	char qstr[1000];
	// 输入数组，遇到换行符停止
	gets_s(qstr);

	// 获取数组长度
	int n = strlen(qstr);

	// 外层循环遍历每一个元素，相当于左指针
	for (int i = 0; i < n; i++) {

		// 定义右指针
		int j = i;
		while (j < n && qstr[j] != ' ') j++;

		// 开始输出数组
		for (int k = i; k < j; k++) cout << qstr[k];
		cout << endl;
		// 交换右指针，获取下一次迭代
		i = j;
	}

	return 0;
}