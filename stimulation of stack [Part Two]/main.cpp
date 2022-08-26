#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int tt, stk[N];

// push el into stack
stk[++tt] = x;

// pop up
stk[--tt];

// Check if the stack is empty
if (tt < 0) {
	return true;
}
else {
	return false;
}

// output top of stack
stk[tt];

int main() {

	return 0;
}