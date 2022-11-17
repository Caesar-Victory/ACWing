#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

// ��Ϊ������ͼ���洢ʱΪ˫��洢�������Ǳ���ֵ�� e[] ���黹�Ǳ���nxtָ��� nxt[]���鶼��Ҫ���ٶ����Ŀռ�
const int N = 1e5 + 10, M = N * 2;

// �洢������С�����ֵ
int n;
int ans = N;
int h[N], e[M], nxt[M], idx;
bool st[N];

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a]; h[a] = idx++;
}

// �� u Ϊ��������ͨ�����ڣ�����������;
// �����ϣ��ȼ��������ҵ��ڵ㣬Ȼ������dfs�����ڵ�
int dfs(int u) {

    // ���Ϊ������
    st[u] = true;
    // sum ��¼��ǰ�����Ĵ�С���䱾�������һ�������Ĭ��ֵΪ1
    // res ��¼ÿһ����������ͨ������ֵ
    int sum = 1, res = 0;

    for (int i = h[u]; i != -1; i = nxt[i]) {

        // �Ȱѱ��ȡ����
        int j = e[i];
        if (!st[j]) {

            // ��s����ʾ��ǰ�����Ĵ�С,���������Ѿ�������ȫ�����ӽڵ㣬��˿��Ը��������ͨ����
            int s = dfs(j);
            // �����ǻ�֪��ǰ�ڵ������֮��ʱ�����ȸ��������ͨ���С
            res = max(res, s);
            // Ȼ��������µ�ǰ�ڵ� u ��ڵ�֮��
            sum += s;
        }
    }
    // ��һ�α�������ʱ��˵�ǵ�ǰ�ڵ��ֵ�Ѿ����½���������ֱ�Ӽ��㵱ǰ�����ͨ���С��
    // ��ͨ���С��Ҳ���������ڵ�ǰ�ڵ������нڵ�Ĳ�ֵ
    res = max(res, n - sum);
    // ���½�����ͼ���Ŀ��ֵ�����߷��е�ɽ��
    ans = min(ans, res);
    return sum;
}

int main(void) {

    cin >> n;

    // �����������ÿ���ڵ㶼����Ϊ-1�� ��ʾ����ڵ���յ�
    memset(h, -1, sizeof h);

    for (int i = 0; i < n; i++) {

        int a, b;
        cin >> a >> b;
        // ����ߵ�˫����ͨ������˵�Ƕ���
        add(a, b), add(b, a);
    }

    // ����ڵ��Ŵ�1��ʼ
    dfs(1);

    cout << ans << endl;

    return 0;
}