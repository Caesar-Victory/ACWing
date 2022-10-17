#include <iostream>

using namespace std;
const int N = 1e3 + 10;

//�ֱ��ʾ����S�ĳ��ȣ�ģʽ�� T �ĳ��ȣ� Next ��������
int slen, tlen, nxt[N];

/*code for KMP algorithm*/

void get_nxt(string t) {
    // KMP �� 0 λ��ʼƥ�䣬�����д˳�ʼֵ������� 1 ��ʼ���� j = 1, k = 0
    // J ָ���� S/T��ͬһλ������, K �� nxt �����Ĭ��ֵ
    int j = 0, k = -1;
    // -1 ��ζ�ŵ�һ���ַ���ǰ��׺�Ͳ����
    nxt[0] = -1;
    while (j < tlen) {
        // �����������ֱ���ζ�ų�ʼ���Լ��¼���ǰ��׺���ַ����������������
        if (k == -1 || t[k] == t[j]) {
            // nxt[j+1] = k + 1, j++, k++;
            nxt[++j] = ++k;
            // ����¼����ַ���ʹ��ǰ��׺����ȣ�����л���
        }
        else {
            k = nxt[k];
        }
    }
}


void im_getnxt(string t) {
    // KMP �� 0 λ��ʼƥ�䣬�����д˳�ʼֵ������� 1 ��ʼ���� j = 1, k = 0
    // J ָ���� S/T��ͬһλ������, K �� nxt �����Ĭ��ֵ
    int j = 0, k = -1;
    // -1 ��ζ�ŵ�һ���ַ���ǰ��׺�Ͳ����
    nxt[0] = -1;
    while (j < tlen) {
        // �����������ֱ���ζ�ų�ʼ���Լ��¼���ǰ��׺���ַ����������������
        if (k == -1 || t[k] == t[j]) {
            if (t[k + 1] = t[j + 1]) {
                // S����T����ǰ�ַ���ͬ����ʱnxt����λ���һ��������Kͬʱ��һ����������t���п��ܴ���t[k+1] = t[j]
                // ��ô��˵�� t[k+1] = t[j] = s[j]���������ֱ����λ�� k �Ļ������޸�ָ�룬��nxt[j+1] = nxt[k+1]
                // ���ƶ� J λ��ָ�룬�ٸ�ֵ��k + 1[��������1]
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
    // KMP �� 0 λ��ʼƥ�䣬�����д˳�ʼֵ������� 1 ��ʼ���� j = 1, k = 0
    // J ָ���� S/T��ͬһλ������, K �� nxt �����Ĭ��ֵ
    int j = 0, k = -1;
    // -1 ��ζ�ŵ�һ���ַ���ǰ��׺�Ͳ����
    nxt[0] = -1;
    while (j < tlen) {
        // �����������ֱ���ζ�ų�ʼ���Լ��¼���ǰ��׺���ַ����������������
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
        // ������������Ƚ���һ���ַ�
        if (j == -1 || s[i] == t[j]) i++, j++;
        // j ���˵� nxt[j]
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