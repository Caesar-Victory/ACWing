#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 开辟空间，自定义容器存储特定值
const int N = 3 * 1e5 + 10;
// 分别存储所有用过的下标以及存储前缀和
int a[N], s[N];

typedef pair<int, int> PII;
vector <PII> add, query;
vector <int> alls;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;

}

// 获取输入，对那个位置插入什么数值
int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({ x, c });
        alls.push_back(x);
    }

    // 获取输入，需要查询那个区间
    for (int i = 0; i < m; i++) {

        int l, r;
        cin >> l >> r;

        query.push_back({ l, r });
        alls.push_back(l);
        alls.push_back(r);
    }
    // 对存储下标的数组进行去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 按照插值数组对数组进行插值
    for (auto item : add) {

        int x = find(item.first);
        a[x] += item.second;
    }

    // 处理前缀和，按照查询数组来运算区间和

    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    for (auto item : query) {

        int l = find(item.first), r = find(item.second);

        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
