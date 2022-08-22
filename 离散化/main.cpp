#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���ٿռ䣬�Զ��������洢�ض�ֵ
const int N = 3 * 1e5 + 10;
// �ֱ�洢�����ù����±��Լ��洢ǰ׺��
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

// ��ȡ���룬���Ǹ�λ�ò���ʲô��ֵ
int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({ x, c });
        alls.push_back(x);
    }

    // ��ȡ���룬��Ҫ��ѯ�Ǹ�����
    for (int i = 0; i < m; i++) {

        int l, r;
        cin >> l >> r;

        query.push_back({ l, r });
        alls.push_back(l);
        alls.push_back(r);
    }
    // �Դ洢�±���������ȥ��
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // ���ղ�ֵ�����������в�ֵ
    for (auto item : add) {

        int x = find(item.first);
        a[x] += item.second;
    }

    // ����ǰ׺�ͣ����ղ�ѯ���������������

    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    for (auto item : query) {

        int l = find(item.first), r = find(item.second);

        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
