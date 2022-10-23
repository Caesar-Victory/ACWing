#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int bruteForce(string s, string t, int sp, int tp) {
	int send = s.length(), tend = t.length();
	while (sp < send && tp < tend) {
		if (s[sp] != t[tp]) {
			sp = sp - tp + 1;
			tp = 0;
		}
		else {
			sp++, tp++;
		}
	}

	if (sp >= tp) return sp - tp;
	else return -1;
}

int main(void) {
	int k = bruteForce("aabacda", "aba", 0, 0);
	printf("%d\n", k);
	return 0;
}