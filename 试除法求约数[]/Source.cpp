#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_divide(int n) {

    vector<int> res;
    for (int i = 1; i <= n / i; i++) {

        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main(void) {

    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        vector<int> res = get_divide(m);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        puts("");
    }
    return 0;
}