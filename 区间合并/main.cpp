#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

// 定义基本的容器结构，便于存储两值
typedef pair<int, int> PII;

vector<PII> megs;

void meg(vector<PII>& megs) {

    // 申请信空间---> 拿一个大圆桶
    vector<PII> res;

    // 一堆碟子先排序
    sort(megs.begin(), megs.end());

    // 生成初始的左右端点
    int st = -2e9, ed = -2e9;

    // 遍历每一张碟子
    for (auto seg : megs) {

        // 如果手上的碟子，小于迭代的碟子的左边界，说明是完全不同起止点的碟子
        if (ed < seg.first) {

            // 如果左端点不是起点，则直接存储当前的碟子左右端点
            if (st != -2e9) res.push_back({ st, ed });
            // 并且直接将手上碟子的左右端点重置为迭代到的对象的 左右端点
            st = seg.first, ed = seg.second;
        }
        else {
            // 否则说明有重合，我们需要保存最大的右端点即可
            ed = max(ed, seg.second);
        }
    }

    // 遍历结束。如果手上碟子的左端点并非起点，则将手上的碟子也存储进去
    if (st != 2e9) res.push_back({ st, ed });

    // 容器对换，完成修改后的传值
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