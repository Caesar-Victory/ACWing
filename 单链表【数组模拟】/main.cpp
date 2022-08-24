#include <iostream>
#include <cstdio>

using namespace  std;

// ��������ռ䣻
const int N = 1e5 + 10;

// head���ֱ�洢����ڵ��ֵ��nextָ��ָ�� ��һ���ڵ��ֵ
// head ��ǰ���õģ����µĽڵ���±꡾�½��ڵ�����кš��� idx �洢��ǰ�Ѿ��ù��ĵ�
// e[]  ����洢�ڵ㣬idx����˳����
int head, idx, e[N], ne[N];

void init() {

	head = -1;
	idx = 0;
}

// ��ͷ�ڵ㿪ʼ����
void add_head(int x) {
	
	// 1. �������idxָ�뽫��������ֵ�洢����
	// 2. �޸ĵ�ǰλ���nex�����е�ֵΪhead,head��Զ����ǰ���õģ����½ڵ���±�
	// 3. head����idx�±꣬
	e[idx] = x, ne[idx] = head, head = idx, idx++;
}

// ��Ԫ�ز��뵽K�ڵ�ĺ���
void add(int k, int x) {

	// �Ƚ�ֵ�洢���� 
	e[idx] = x;
	// ������ڵ��nextָ�룬ָ�� K�ڵ�ĺ�һ���ڵ�
	ne[idx] = ne[k];
	// ��ֵ���ݸ��±�ΪK�Ľڵ�
	ne[k] = x;
	idx++;
}

// ��K��ڵ�ɾ�������޸�ָ��ָ��Ľڵ㡿
void remove(int k) {

	// ne[ne[k]] ����K�ڵ����һ���ڵ�
	ne[k - 1] = ne[ne[k]];
}

int main() {

	return 0;
}