#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

// ��������������ṹ�����ڴ洢��ֵ
typedef pair<int, int> PII;

vector<PII> megs;

void meg(vector<PII>& megs) {

    // �����ſռ�---> ��һ����ԲͰ
    vector<PII> res;

    // һ�ѵ���������
    sort(megs.begin(), megs.end());

    // ���ɳ�ʼ�����Ҷ˵�
    int st = -2e9, ed = -2e9;

    // ����ÿһ�ŵ���
    for (auto seg : megs) {

        // ������ϵĵ��ӣ�С�ڵ����ĵ��ӵ���߽磬˵������ȫ��ͬ��ֹ��ĵ���
        if (ed < seg.first) {

            // �����˵㲻����㣬��ֱ�Ӵ洢��ǰ�ĵ������Ҷ˵�
            if (st != -2e9) res.push_back({ st, ed });
            // ����ֱ�ӽ����ϵ��ӵ����Ҷ˵�����Ϊ�������Ķ���� ���Ҷ˵�
            st = seg.first, ed = seg.second;
        }
        else {
            // ����˵�����غϣ�������Ҫ���������Ҷ˵㼴��
            ed = max(ed, seg.second);
        }
    }

    // ����������������ϵ��ӵ���˵㲢����㣬�����ϵĵ���Ҳ�洢��ȥ
    if (st != 2e9) res.push_back({ st, ed });

    // �����Ի�������޸ĺ�Ĵ�ֵ
    megs = res;
}

int main() {

    int n;
    cin >> n;

    while (n--) {

        int l, r;
        cin >> l >> r;

        megs.push_back({ l, r });
    }

    meg(megs);

    cout << megs.size() << endl;
}