#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>


// 这里应当理解为用 x 替换first
#define x first
#define y second

using namespace std;

#include <cstdio>
#include <iostream>


// 这里应当理解为用 x 替换first
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10, M = N * N;

int n, m;
// 申请循环使用的队列空间
PII q[M];
// 字符地图，收纳所有的 'W' 和普通陆地
char g[N][N];
// 判重数组
bool st[N][N];

void bfs(int sx, int sy) {
    
    // 初始化队列的头尾指针
    int hh=0, tt=0;
    // 初始化队列和标记数组，初始化队列亦是如此，BFS中的队列本质是换基，初始化只是给它找一个基点
    q[0] = {sx, sy};
    // 初始化标记是因为每一次传参就意味着有一个坐标被用过了；
    st[sx][sy] = true;
    
    while (hh <= tt) {
        // 从队头取出元素，则头指针自增, 取出第一个元素，可以直接取出，下一次访问时再读取自增
        PII t = q[hh++];
        // 如何构造八连通量呢？挖去3*3矩阵核心点，保留四周；
        for (int i = t.x - 1; i <= t.x + 1; i++) {
            
            for(int j = t.y - 1; j <= t.y + 1; j++) {
                
                // 跳过中心点；在所有坐标中，只有对角线的四个坐标，完全不与中心点的横坐标或者纵坐标相等，
                // 因此这里只有横纵坐标完全与取出来的中心点相同才会跳过
                if (i == t.x && j == t.y) continue;
                // 不能撞墙，也就是超出边界
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                // 不能走到陆地或者搜索已经搜过的地方
                if (g[i][j] == '.' || st[i][j]) continue;
                
                // 从队尾插入元素，则尾指针自增；本次就需要将元素插入进去，因此直接前++
                q[++tt] = {i, j};
                st[i][j] = true;
            }
        }
    }
    
}

int main(void) {
    
    int cnt=0;
    
    scanf("%d%d", &n, &m);
    
    // 逐行读取输入
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    
    // for (int i = 0; i < n; i++) printf("%s", g[i]), puts("");
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            
            // 只有当该点是水域，且没有被搜索过
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
// 申请循环使用的队列空间
PII q[M];
// 字符地图，收纳所有的 'W' 和普通陆地
char g[N][N];
// 判重数组
bool st[N][N];

void bfs(int sx, int sy) {

    // 初始化队列的头尾指针
    int hh = 0, tt = 0;
    // 初始化队列和标记数组，初始化队列亦是如此，BFS中的队列本质是换基，初始化只是给它找一个基点
    q[0] = { sx, sy };
    // 初始化标记是因为每一次传参就意味着有一个坐标被用过了；
    st[sx][sy] = true;

    while (hh <= tt) {
        // 从队头取出元素，则头指针自增, 取出第一个元素，可以直接取出，下一次访问时再读取自增
        PII t = q[hh++];
        // 如何构造八连通量呢？挖去3*3矩阵核心点，保留四周；
        for (int i = t.x - 1; i <= t.x + 1; i++) {

            for (int j = t.y - 1; j <= t.y + 1; j++) {

                // 跳过中心点；在所有坐标中，只有对角线的四个坐标，完全不与中心点的横坐标或者纵坐标相等，
                // 因此这里只有横纵坐标完全与取出来的中心点相同才会跳过
                if (i == t.x && j == t.y) continue;
                // 不能撞墙，也就是超出边界
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                // 不能走到陆地或者搜索已经搜过的地方
                if (g[i][j] == '.' || st[i][j]) continue;

                // 从队尾插入元素，则尾指针自增；本次就需要将元素插入进去，因此直接前++
                q[++tt] = { i, j };
                st[i][j] = true;
            }
        }
    }

}

int main(void) {

    int cnt = 0;

    scanf("%d%d", &n, &m);

    // 逐行读取输入
    for (int i = 0; i < n; i++) scanf("%s", g[i]);

    // for (int i = 0; i < n; i++) printf("%s", g[i]), puts("");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            // 只有当该点是水域，且没有被搜索过
            if (g[i][j] == 'W' && !st[i][j]) {

                bfs(i, j);
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}