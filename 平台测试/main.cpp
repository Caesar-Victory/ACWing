#include <iostream>

using namespace std;

int main() {

	// 测试long double 占用字节数，具体取决于编译器
	printf("%d %d", sizeof(long double), sizeof(int));
	// 8， 4
	return 0;
}