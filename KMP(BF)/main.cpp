#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string mains = "ABCDEFABCDOABFO", subs = "ABCD0";
	int m = 0, s = 0;
	int mlen = mains.length(), slen = subs.length();
	while (m < mlen && s < slen) {
		if (mains[m] != subs[s]) {
			m = m - s + 1;
			s = 0;
		}
		else {
			m++, s++;
		}
	}

	if (m >= s) printf("%d\n", m - s);
	else printf("None!");

	return 0;
}