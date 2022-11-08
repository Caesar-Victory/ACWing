#include <iostream>
#include <cstdio>

using namespace std;

// 该函数用于找下一个质数
int main(void) {

	// 外层循环，设定起点并且开始递增
	for (int i = 100000; i++;) {
		// 假设当前数就是质数，应当满足其开二次方内的数，除了1以外均不能作为因数，如果存在这样的数说明当前数 i 不是质数，修改标记并且结束迭代
		// 每次当前数查找开方内的因数结束后判断标记，如果未变更立即输出，并且结束循环
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