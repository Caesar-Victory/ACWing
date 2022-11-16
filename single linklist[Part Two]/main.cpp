#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

// head ͷ�ڵ���±�
// e[] �������ΰ���λ��洢��Ӧ��ֵ
// nxt[] ����洢��ǰ�ڵ����һ���ڵ��λ�á��ȼ���λ��
// ������ͬһ��λ����ͬ����Ϊ�ֱ�洢��ֵ��nxtָ��ָ��Ķ���
int head, idx, e[N], ne[N];

// ��ʼ����ͷ�ڵ�Ĭ��Ϊ��-1
void init(void) {
    head = -1;
    idx = 0;
}

void remove(int k) {

    // ��ǰ�ڵ�ָ��ǰ�ڵ����һ���ڵ�
    ne[k] = ne[ne[k]];
}

// ��ͷ�ڵ����
void add_head(int k) {

    // e����������ʹ��idxָ�뽫��ֵ�洢����
    e[idx] = k;
    // �����±꣬�����½ڵ�ġ�nexָ��ָ��ͷ�ڵ�[ָ�����һ��ֵ]
    // ������������ṹ���ǵ������˴�����ĺ���͹�ϣ��������������岻һ����������һ������
    ne[idx] = head;
    // head ָ�������½ڵ� e[idx]���Դ�ֵ�ķ�ʽ
    head = idx;
    idx++;
}

// ��ĳ���ڵ�ĺ������
void add_rear(int k, int x) {

    // ������������ڵ��ֵ���洢����
    e[idx] = x;
    // �����±�idx�ƶ�nexָ�룬����K����һ���ڵ�
    ne[idx] = ne[k];
    // k����һ���ڵ���idx�����ڵ㣬��Ϊnex����ʼ�մ洢��һ���ڵ���±꣬��idx�Ѿ��ù���
    ne[k] = idx;
    idx++;
}

int main() {
    int m;
    cin >> m;

    init();

    while (m--) {
        char flag;
        cin >> flag;

        if (flag == 'H') {

            int val;
            cin >> val;

            add_head(val);
        }
        else if (flag == 'D') {

            int k;
            cin >> k;

            //���У��� k = 0ʱ����ζ��ɾ��ͷ�ڵ㣬��ôֱ�Ӱ���һ���ɲ���ڵ�ֱ��ָ�� ��nex������head����һ���ڵ�
            if (!k) head = ne[head];

            remove(k - 1);
        }
        else if (flag == 'I') {
            int k, x;
            cin >> k >> x;

            add_rear(k - 1, x);
        }

    }

    // e�洢����ָ����������ne���飬iʼ�մ�nex������ȡ���±�--->�ƶ�ָ��
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
    cout << endl;

    return 0;
}