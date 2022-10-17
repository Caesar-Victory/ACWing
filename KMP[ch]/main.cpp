#include <iostream>

using namespace std;
const int N = 1e3 + 10;

//分别表示主串S的长度，模式串 T 的长度， Next 回退数组
int slen, tlen, nxt[N];

/*code for KMP algorithm*/

void get_nxt(string t) {
    // KMP 从 0 位序开始匹配，所以有此初始值，如果从 1 开始，则 j = 1, k = 0
    // J 指的是 S/T串同一位序的起点, K 是 nxt 数组的默认值
    int j = 0, k = -1;
    // -1 意味着第一个字符就前后缀就不相等
    nxt[0] = -1;
    while (j < tlen) {
        // 两个条件，分别意味着初始化以及新加入前后缀的字符可以满足它们相等
        if (k == -1 || t[k] == t[j]) {
            // nxt[j+1] = k + 1, j++, k++;
            nxt[++j] = ++k;
            // 如果新加入字符，使得前后缀不相等，则进行回退
        }
        else {
            k = nxt[k];
        }
    }
}


void im_getnxt(string t) {
    // KMP 从 0 位序开始匹配，所以有此初始值，如果从 1 开始，则 j = 1, k = 0
    // J 指的是 S/T串同一位序的起点, K 是 nxt 数组的默认值
    int j = 0, k = -1;
    // -1 意味着第一个字符就前后缀就不相等
    nxt[0] = -1;
    while (j < tlen) {
        // 两个条件，分别意味着初始化以及新加入前后缀的字符可以满足它们相等
        if (k == -1 || t[k] == t[j]) {
            if (t[k + 1] = t[j + 1]) {
                // S串和T串当前字符相同，此时nxt数组位序加一，计数器K同时加一，但由于在t串中可能存在t[k+1] = t[j]
                // 那么则说明 t[k+1] = t[j] = s[j]，因此我们直接在位序 k 的基础上修改指针，即nxt[j+1] = nxt[k+1]
                // 先移动 J 位序指针，再赋值与k + 1[计数器加1]
                nxt[j + 1] = nxt[k + 1];
            }
            else {
                nxt[j + 1] = k + 1;
            }
            j++, k++;
        }
        else {
            k = nxt[k];
        }
    }
}


void get_nextval(string t) {
    // KMP 从 0 位序开始匹配，所以有此初始值，如果从 1 开始，则 j = 1, k = 0
    // J 指的是 S/T串同一位序的起点, K 是 nxt 数组的默认值
    int j = 0, k = -1;
    // -1 意味着第一个字符就前后缀就不相等
    nxt[0] = -1;
    while (j < tlen) {
        // 两个条件，分别意味着初始化以及新加入前后缀的字符可以满足它们相等
        if (k == -1 || t[k] == t[j]) {
            if (t[++j] == t[++k]) nxt[j] = nxt[k];
            else nxt[j] = k;
        }
        else {
            k = nxt[k];
        }
    }
}

int kmp(string s, string t, int pos) {
    int i = pos, j = 0, sum = 0;
    slen = s.length(), tlen = t.length();
    im_getnxt(t);
    while (i < slen && j < tlen) {
        sum++;
        // 如果相等则继续比较下一个字符
        if (j == -1 || s[i] == t[j]) i++, j++;
        // j 回退到 nxt[j]
        else j = nxt[j];
    }
    if (j >= tlen) return i - tlen + 1;
    else return -1;
}

int main(void) {
    string s, t;
    cin >> s >> t;
    cout << kmp(s, t, 0) << endl;
    return 0;
}