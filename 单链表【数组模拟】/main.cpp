#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

// head: 指向下一个新的可插入节点
// idx: 所有节点的下标
int head, idx, e[N], ne[N];

// 初始化，头节点默认为：-1
void init(void) {
    head = -1;
    idx = 0;
}

void remove(int k) {

    // 当前节点指向当前节点的下一个节点
    ne[k] = ne[ne[k]];
}

// 从头节点插入
void add_head(int k) {

    // e是链表，首先使用idx指针将数值存储起来
    e[idx] = k;
    // 利用下标，将【新节点的】nex指针指向头节点
    ne[idx] = head;
    // head 接收idx指针
    head = idx;
    idx++;
}

// 从某个节点的后面插入
void add_rear(int k, int x) {

    // 照例将待插入节点的值，存储起来
    e[idx] = x;
    // 可用下标idx推动nex指针，接受K的下一个节点
    ne[idx] = ne[k];
    // k的下一个节点与idx交换节点，因为nex数组始终存储下一个节点的下标，而idx已经用过了
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

            //特判：当 k = 0时，意味着删除头节点，那么直接把下一个可插入节点直接指向 在nex数组中head的下一个节点
            if (!k) head = ne[head];

            remove(k - 1);
        }
        else if (flag == 'I') {
            int k, x;
            cin >> k >> x;

            add_rear(k - 1, x);
        }

    }

    // e存储链表，指针推移依靠ne数组，i始终从nex数组中取出下标--->移动指针
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
    cout << endl;

    return 0;
}