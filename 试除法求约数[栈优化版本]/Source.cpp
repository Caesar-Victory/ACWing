#include <iostream>
#include <stack>

using namespace std;

void get_divide(int n) {

    stack<int> res;
    for (int i = 1; i <= n / i; i++) {

        if (n % i == 0) {

            // 成对约数中较小数直接输出，较大数直接存储
            cout << i << " ";
            if (i != n / i) res.push(n / i);
        }
    }

    // 由于枚举成对约数中的较小数，从小到大，因此存入栈中的数字则是由大到小，由因为栈结构将会从小到大输出
    while (res.size()) {
        cout << res.top() << " ";
        res.pop();
    }
}

int main(void) {

    int n;
    scanf("%d", &n);
    while (n--) {

        int m;
        scanf("%d", &m);
        get_divide(m);
        puts("");
    }
}