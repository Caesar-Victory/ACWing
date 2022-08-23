#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// ��������Ϊ���ṹ��������Զ��峣�����������飬ȫ�ֱ�������������
typedef pair<int, int> PII;

const int N = 3 * 1e5 + 10;

int a[N], s[N];
int n, m;

vector<int> alls;
vector<PII> add, query;

// ȥ�� ---> �����������������ǵ�һ��Ԫ�ء��±���㡿�������ǰһ���������
vector<int> ::iterator unique(vector<int>& a) {

    int j = 0;
    for (int i = 0; i <= a.size(); i++) {

        if (!i || a[i] != a[i - 1]) {
            a[j++] = a[i];
        }
    }

    return a.begin() + j;
}

// ��alls�������ṩ�Զ��ֵķ�ʽ�����±꣬�ֱ�Ϊ add & query������ã����ڿ��ٲ��ҷ��ظ��±���в�ֵ�ͼ��������
int find(int x) {

    int l = 0, r = alls.size() - 1;

    while (l < r) {

        int mid = (l + r) >> 1;

        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    // ǰ׺�͵��±��Ǵ�1��ʼ��
    return r + 1;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        int x, c;
        cin >> x >> c;

        // �ȴ洢��ֵ���飬�ֱ�Ϊ�±�ͱ������ֵ
        add.push_back({ x, c });

        // �����ù����±�����alls�����У���ֵǰ�����ȥ��
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {

        int l, r;
        cin >> l >> r;

        // ��ѯ����ɶԴ洢����
        query.push_back({ l, r });

        // ����Ҳ���±꣬��˷����δ�������
        alls.push_back(l);
        alls.push_back(r);
    }

    // �����ֵͬ����
    sort(alls.begin(), alls.end());
    // ��ֵ��ǰ�Ⱥ�˳�򣬺���ȫ��ֵͬ
    // alls.erase(unique(alls.begin(), alls.end()), alls.end());
    alls.erase(unique(alls), alls.end());

    for (auto item : add) {

        // �±궼��Ҫ��alls������Ѱ��
        int x = find(item.first);
        // ���﷨�൱�� element[0], element[1]
        a[x] += item.second;
    }

    // �ȼ���ǰ׺�ͣ��±��ֵ��Ϊ�� [1, alls.size()]
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];


    for (auto item : query) {

        // ��Ѱ���±꣬�ڼ���ǰ׺��
        int l = find(item.first), r = find(item.second);

        // l - 1����Ϊǰ׺��
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}