#define  _CRT_SECURE_NO_WARNINGS
// ֵ��Ͷ�����ƥ�䣬��ģ���ϴ�1.9 * 1e10
// ��Ա�ж��Ƿ�ͨ������ƥ��ķ�ʽ��֤
// ������� 1e5 �ĵ�һ������
#include <cstring>
#include <iostream>

using namespace std;

// ���Խ��ռ俪Ϊ����������������ʽԼ���������ܽ�����ײ�ĸ���
const int N = 100003;

// �ֱ��ʾ��ۣ�e:�洢��ֵ��ne:��һ��ֵ����һ��λ�á����ӹ�ϵ��
// idx ��ʾ��ǰ�õ�����һ��λ��
int h[N], ne[N], e[N], idx;

// ��һ����������ɹ�ϣӳ�� Ҳ���� +- 1e9 ---> 1e5
void insert(int x) {

    // +N �� % N Ŀ����������ʼ�ձ���Ϊ����
    // ����ȡģ������˵��NΪ�������Ϊ����NΪ�������Ϊ����
    // ��ȡģ�ټӣ�ǰ��������ȡģ����Ϊ ����ֵ x �� N ����1e9�����������������ͣ�N������ X�Գ壬ʹ���Ϊһ������
    // �˴�ʹ����˸��ӵ�ȡģ����ͣ���ȡģ����Ϊ�˵� X ��ֵΪ����ʱ�������ȻΪ����
    // ��֪: k ������Ϊ��ϣ����±�
    int k = (x % N + N) % N;
    // �Ȱ������洢����
    e[idx] = x;
    // ��next ���飬�Ե�ǰ idx ��ֵ��Ϊ����������λ���ֵ��ֵΪ h[k]�� ��ʱh[k]��idx�ȼۣ����ǳ䵱�����λ��
    ne[idx] = h[k];
    // �Ǳ���
    h[k] = idx++;
    // K ���ǹ�ϣֵ

}

bool find(int x) {

    int k = (x % N + N) % N;
    // �����ҵ���ϣ���е�ӳ��㣬ת�������п�ʼ����ֵ
    // �� h[k]�䵱�±꣬�˴�h[k]�������Ϊ���ӣ��ӹ�ϣ��תս��������
    // h[k] �洢���ǵ�һ���ڵ���±�
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}

int main(void) {
    int n;
    scanf("%d", &n);

    // �ڽ�Ԫ�ز�������ǰ���ȰѲ���գ���ָ��һ���� -1 ����ʾ
    // �� h[] �����е�ֵȫ����ʼ��Ϊ-1�� �����е�����ͷָ���ʼ��Ϊ-1
    // ͷ�ļ���csting
    memset(h, -1, sizeof h);

    while (n--) {
        char op[2];
        int x;
        // �� %s ��ȡ�ַ��������������ո񣬻س��ͻ��з�
        scanf("%s%d", op, &x);

        // ע��˴�Ϊ ������ 'I' ˫���Żᵼ���ַ������е��ַ����볣�� �ַ���ƥ��
        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}

// ����������
// https://www.acwing.com/activity/content/code/content/45308/
// ��Ƶ���������
// https://www.acwing.com/video/266/
// �����ϣ��ײ�����ַ�ʽ���Լ�memset�������ơ�δ���ա�
// https://www.acwing.com/solution/content/33699/
// https://www.cnblogs.com/east7/p/12594894.html
// ��չ�Ķ� 0x3f
// https://blog.csdn.net/lyj2014211626/article/details/65481630