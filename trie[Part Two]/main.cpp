#include <iostream>

using namespace std;

const int N = 1e5 + 10;


// son: N 表示树的深度, 26 表示树的广度，每一层最多有26种可能的字母; 
// cnt[]数组统计以当前字母结尾的字符串有多少个，也可以理解为统计某一层以该层字母结尾的总和
// idx 当前用到的那个下标,注意: 下标为0的节点，既是根节点，又是空节点
int son[N][26], cnt[N], idx;
char str[N];

void insert(char str[]) {

    // P 表示从根节点那一层开始匹配，第零层无任何字母，因此会直接被跳过，由 idx跳到第一层
    int p = 0;
    //  str[i] 相当于 i != -1
    for (int i = 0; str[i]; i++) {

        // 将 a - z 的字母，映射为 0 - 25 的数字
        int u = str[i] - 'a';
        // 如果字典树中还没有此字母作为节点的，则先将其创建出来,直接从1开始,因为0为根节点[因此为前++]
        if (!son[p][u]) son[p][u] = ++idx;
        // 每个节点存储的值,是下一个元素的层数,如果当前节点并非某个字符串的结尾,则存储的值是 当前层数 + 1
        p = son[p][u];

    }
    // for 循环遍历结束时，P指向的字母就是整个插入字符串的最后一个单词所在的层数
    // P 也是某个字符串的长度
    // 表示当前层数某个单词结尾的总和
    cnt[p]++;
}

int query(char str[]) {

    // P 表示从根节点那一层开始匹配，第零层无任何字母，因此会直接被跳过，由 idx跳到第一层
    int p = 0;
    for (int i = 0; str[i]; i++) {

        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main(void) {

    int n;
    scanf("%d", &n);
    while (n--) {
        // 任意字符数组的末尾一定是 '\0'，用char类型而不是 string 是为了避免空格
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I') insert(str);
        // 已经插入的字符串不会重复插入
        else printf("%d\n", query(str));
    }

    return 0;
}

