#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;

int n;
double a[N][N];

void out(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << a[i][j] << " ";
        }
        puts(" ");
    }
}
// �����߼����ȿ�����������һ��λ��
// ��˹_Լ����Ԫ��
int gauss(void) {

    // �У���
    int c, r;
    // ��������ΪԴ�㣬���Һ�����Ϊ����������
    // n Ϊ �У� n + 1 Ϊ��
    for (c = 0, r = 0; c < n; c++) {
        // ��һ������t�洢����ֵ�����У�Ĭ��Ϊ��ǰ��
        // for ѭ����������[ǰ�е�]�����У��ҵ�����ֵ������һ�У����丳ֵ������t
        int t = r;
        // �ӵ�ǰ�п�ʼ���������е���
        for (int i = r; i < n; i++) {
            // �� c �еľ���ֵ ���� ��ѡ�𰸵ľ���ֵ
            if (fabs(a[i][c]) > fabs(a[t][c])) {
                t = i;
            }
        }


        // ��ֵ��������Ϊ0.00001�����Ϊ���⾫�����������趨���
        // ��ǰ����ֵ������[��ǰ��] ��ȻС�� 0 ������
        if (fabs(a[t][c]) < eps) continue;



        // [���һ�� ���� �еľ���ֵ������һ��]��ÿһ��
        for (int i = 0; i <= n; i++) swap(a[t][i], a[r][i]);

        // ����һ�е�ϵ����Ϊ1��ע�⵹�򣬱��⸲�Ǳ��ϵ�������ָ����ÿһ���������ֵ�ϵ����
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];

        // ��ǰ��c�е�ÿһ��ȫ������Ϊ��
        // �������е��У����Ϊ��һ�У���ǰ�� + 1����Ϊ��Ԫ�Ѿ�ȷ��
        // �����£�������
        for (int i = r + 1; i < n; i++) {
            // ���ڵ�ǰ�У����������е�ֵ����0�ſ�ʼ����
            if (fabs(a[i][c]) > eps) {
                // ��������У��ɱ����������� - ��ǰ�е�ÿһ�� * ��ǰ�е�ÿһ��
                // �������һ�������˳��պ��෴�����������ʱ����Ե�n
                for (int j = n; j >= c; j--) {
                    // �Ź������ 8 = 2 * 4
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }

    // out();

    // ����жϽ�ĸ������Ե�ǰ��Ϊ��׼���������е��У�ֻҪ��һ����ֵ����ֵ��Ϊ��
    if (r < n) {
        // �������һ�е�ÿһ��
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) {
                return 2;  // �޽�
            }
        }
        return 1;  // ��������
    }
    // �����µ��ϣ��ٴ�����
    // ����������е��У��Ե�ǰ��Ϊ��׼������������е���
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // ���һ�е�ÿһ�� �ۼ� ���һ�еĵ�ǰ�У�ע�����л�����
            // 9 = 8 * 8
            a[i][n] -= a[i][j] * a[j][n];
        }
    }

    return 0;  // ��Ψһ��
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    int t = gauss();
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else {
        // �������е���
        for (int i = 0; i < n; i++) {
            // �����ֵС�ڼ�С��������Ϊ0
            if (fabs(a[i][n]) < eps) a[i][n] = 0;
            // ��ӡ��С�������λ����ӡ���һ�е�������
            printf("%.2lf\n", a[i][n]);
        }
    }
    return 0;
}

// https://www.acwing.com/video/304/
// https://www.acwing.com/activity/content/code/content/53389/