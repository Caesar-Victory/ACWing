#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 声明依次为：结构体别名，自定义常量；声明数组，全局变量和声明容器
typedef pair<int, int> PII;

const int N = 3 * 1e5 + 10;

int a[N], s[N];
int n, m;

vector<int> alls;
vector<PII> add, query;

// 去重 ---> 满足两个条件，不是第一个元素【下标非零】，其次与前一个数不相等
vector<int> ::iterator unique(vector<int>& a) {

    int j = 0;
    for (int i = 0; i <= a.size(); i++) {

        if (!i || a[i] != a[i - 1]) {
            a[j++] = a[i];
        }
    }

    return a.begin() + j;
}

// 在alls数组中提供以二分的方式查找下标，分别为 add & query数组调用，便于快速查找非重复下标进行插值和计算区间和
int find(int x) {

    int l = 0, r = alls.size() - 1;

    while (l < r) {

        int mid = (l + r) >> 1;

        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    // 前缀和的下标是从1开始的
    return r + 1;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        int x, c;
        cin >> x >> c;

        // 先存储插值数组，分别为下标和被插入的值
        add.push_back({ x, c });

        // 所有用过的下标存放在alls数组中，插值前会进行去重
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {

        int l, r;
        cin >> l >> r;

        // 查询数组成对存储区间
        query.push_back({ l, r });

        // 区间也是下标，因此分两次存入数组
        alls.push_back(l);
        alls.push_back(r);
    }

    // 排序后，同值相邻
    sort(alls.begin(), alls.end());
    // 异值在前先后顺序，后面全是同值
    // alls.erase(unique(alls.begin(), alls.end()), alls.end());
    alls.erase(unique(alls), alls.end());

    for (auto item : add) {

        // 下标都需要在alls数组中寻找
        int x = find(item.first);
        // 此语法相当于 element[0], element[1]
        a[x] += item.second;
    }

    // 先计算前缀和，下标的值域为： [1, alls.size()]
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];


    for (auto item : query) {

        // 先寻找下标，在计算前缀和
        int l = find(item.first), r = find(item.second);

        // l - 1是因为前缀和
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}