#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;
int n;
const int N = 10003;
int h[N], e[N], nxt[N], idx;

void insert(int x) {

	int k = (x % N + N) % N;
	e[idx] = x;
	nxt[idx] = h[k];
	h[k] = idx++;

}

bool find(int x) {

	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = nxt[i]) {
		if (e[i] == x) {
			return true;
		}
	}
	return false;
}

int main(void) {

	scanf("%d", &n);

	while (n--) {
		int x;
		char op[2];
		scanf("%d%s", &x, op);

		if (*op == "I") {
			insert(x);
		}
		else {
			if (find(x) == true) {
				puts("true");
			}
			else {
				puts("false");
			}
		}
	}

}