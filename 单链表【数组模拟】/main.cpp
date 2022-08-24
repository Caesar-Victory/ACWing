#include <iostream>
#include <cstdio>

using namespace  std;

// 申请数组空间；
const int N = 1e5 + 10;

// head：分别存储链表节点的值，next指针指向 下一个节点的值
// head 当前可用的，最新的节点的下标【新建节点的序列号】， idx 存储当前已经用过的点
// e[]  负责存储节点，idx按照顺序编号
int head, idx, e[N], ne[N];

void init() {

	head = -1;
	idx = 0;
}

// 从头节点开始插入
void add_head(int x) {
	
	// 1. 用数组和idx指针将待插入数值存储起来
	// 2. 修改当前位序的nex数组中的值为head,head永远代表当前可用的，最新节点的下标
	// 3. head接受idx下标，
	e[idx] = x, ne[idx] = head, head = idx, idx++;
}

// 将元素插入到K节点的后面
void add(int k, int x) {

	// 先将值存储起来 
	e[idx] = x;
	// 将插入节点的next指针，指向 K节点的后一个节点
	ne[idx] = ne[k];
	// 将值传递给下标为K的节点
	ne[k] = x;
	idx++;
}

// 将K后节点删除【仅修改指针指向的节点】
void remove(int k) {

	// ne[ne[k]] 代表K节点的下一个节点
	ne[k - 1] = ne[ne[k]];
}

int main() {

	return 0;
}