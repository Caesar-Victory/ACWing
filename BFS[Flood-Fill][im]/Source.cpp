#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>


// ����Ӧ�����Ϊ�� x �滻first
#define x first
#define y second

using namespace std;

#include <cstdio>
#include <iostream>


// ����Ӧ�����Ϊ�� x �滻first
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10, M = N * N;

int n, m;
// ����ѭ��ʹ�õĶ��пռ�
PII q[M];
// �ַ���ͼ���������е� 'W' ����ͨ½��
char g[N][N];
// ��������
bool st[N][N];

void bfs(int sx, int sy) {
    
    // ��ʼ�����е�ͷβָ��
    int hh=0, tt=0;
    // ��ʼ�����кͱ�����飬��ʼ������������ˣ�BFS�еĶ��б����ǻ�������ʼ��ֻ�Ǹ�����һ������
    q[0] = {sx, sy};
    // ��ʼ���������Ϊÿһ�δ��ξ���ζ����һ�����걻�ù��ˣ�
    st[sx][sy] = true;
    
    while (hh <= tt) {
        // �Ӷ�ͷȡ��Ԫ�أ���ͷָ������, ȡ����һ��Ԫ�أ�����ֱ��ȡ������һ�η���ʱ�ٶ�ȡ����
        PII t = q[hh++];
        // ��ι������ͨ���أ���ȥ3*3������ĵ㣬�������ܣ�
        for (int i = t.x - 1; i <= t.x + 1; i++) {
            
            for(int j = t.y - 1; j <= t.y + 1; j++) {
                
                // �������ĵ㣻�����������У�ֻ�жԽ��ߵ��ĸ����꣬��ȫ�������ĵ�ĺ����������������ȣ�
                // �������ֻ�к���������ȫ��ȡ���������ĵ���ͬ�Ż�����
                if (i == t.x && j == t.y) continue;
                // ����ײǽ��Ҳ���ǳ����߽�
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                // �����ߵ�½�ػ��������Ѿ��ѹ��ĵط�
                if (g[i][j] == '.' || st[i][j]) continue;
                
                // �Ӷ�β����Ԫ�أ���βָ�����������ξ���Ҫ��Ԫ�ز����ȥ�����ֱ��ǰ++
                q[++tt] = {i, j};
                st[i][j] = true;
            }
        }
    }
    
}

int main(void) {
    
    int cnt=0;
    
    scanf("%d%d", &n, &m);
    
    // ���ж�ȡ����
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    
    // for (int i = 0; i < n; i++) printf("%s", g[i]), puts("");
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            
            // ֻ�е��õ���ˮ����û�б�������
            if (g[i][j] == 'W' && !st[i][j]) {
                
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

const int N = 1e3 + 10, M = N * N;

int n, m;
// ����ѭ��ʹ�õĶ��пռ�
PII q[M];
// �ַ���ͼ���������е� 'W' ����ͨ½��
char g[N][N];
// ��������
bool st[N][N];

void bfs(int sx, int sy) {

    // ��ʼ�����е�ͷβָ��
    int hh = 0, tt = 0;
    // ��ʼ�����кͱ�����飬��ʼ������������ˣ�BFS�еĶ��б����ǻ�������ʼ��ֻ�Ǹ�����һ������
    q[0] = { sx, sy };
    // ��ʼ���������Ϊÿһ�δ��ξ���ζ����һ�����걻�ù��ˣ�
    st[sx][sy] = true;

    while (hh <= tt) {
        // �Ӷ�ͷȡ��Ԫ�أ���ͷָ������, ȡ����һ��Ԫ�أ�����ֱ��ȡ������һ�η���ʱ�ٶ�ȡ����
        PII t = q[hh++];
        // ��ι������ͨ���أ���ȥ3*3������ĵ㣬�������ܣ�
        for (int i = t.x - 1; i <= t.x + 1; i++) {

            for (int j = t.y - 1; j <= t.y + 1; j++) {

                // �������ĵ㣻�����������У�ֻ�жԽ��ߵ��ĸ����꣬��ȫ�������ĵ�ĺ����������������ȣ�
                // �������ֻ�к���������ȫ��ȡ���������ĵ���ͬ�Ż�����
                if (i == t.x && j == t.y) continue;
                // ����ײǽ��Ҳ���ǳ����߽�
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                // �����ߵ�½�ػ��������Ѿ��ѹ��ĵط�
                if (g[i][j] == '.' || st[i][j]) continue;

                // �Ӷ�β����Ԫ�أ���βָ�����������ξ���Ҫ��Ԫ�ز����ȥ�����ֱ��ǰ++
                q[++tt] = { i, j };
                st[i][j] = true;
            }
        }
    }

}

int main(void) {

    int cnt = 0;

    scanf("%d%d", &n, &m);

    // ���ж�ȡ����
    for (int i = 0; i < n; i++) scanf("%s", g[i]);

    // for (int i = 0; i < n; i++) printf("%s", g[i]), puts("");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            // ֻ�е��õ���ˮ����û�б�������
            if (g[i][j] == 'W' && !st[i][j]) {

                bfs(i, j);
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}