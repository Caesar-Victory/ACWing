#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_divide(int n) {

    vector<int> res;
    // 约数也是成对出现的，
    // 除了平方根以外，其余数字均在枚举到成对约数中较小的一个时，通过if判断存储另外一个
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

// https://www.acwing.com/video/294/
// https://www.acwing.com/activity/content/code/content/49976/