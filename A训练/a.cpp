#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define int long long

const int N = 3005; // 根据题目点数调整，通常适用于 N <= 5000 的情况
const int inf = 1e18 + 5;

// 如果是给定的边，可以用邻接矩阵存图；如果是完全图/动态计算边权，则不需要此矩阵
int g[N][N]; 
int dist[N]; // dist[i] 表示点 i 到当前生成树集合的最短距离
int vis[N];  // 标记点是否已经加入生成树

void solve() {
    int n, m; 
    cin >> n >> m;
    
    // 初始化图矩阵为无穷大，对角线为 0
    rep(i, 1, n) rep(j, 1, n) g[i][j] = (i == j ? 0 : inf);
    
    // 读入边
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        // 处理重边，保留最小的
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w); 
    }

    // 初始化距离为无穷大，标记为未访问
    rep(i, 1, n) {
        dist[i] = inf;
        vis[i] = 0;
    }
    
    int ans = 0;
    dist[1] = 0; // 从 1 号点开始
    
    // 找 n 次，每次加入一个点到生成树中
    rep(i, 1, n) {
        int u = -1;
        int mn = inf;
        
        // 1. 在未加入生成树的点中，找距离集合最近的点
        rep(j, 1, n) {
            if (!vis[j] && dist[j] < mn) {
                mn = dist[j];
                u = j;
            }
        }
        
        // 如果找不到联通的点了，说明图不连通
        if (u == -1) {
            cout << "orz" << '\n';
            return;
        }
        
        // 2. 把找到的点加入生成树
        vis[u] = 1;
        ans += mn;
        
        // 3. 用刚加入的点 u 更新其他未加入的点到集合的距离
        rep(v, 1, n) {
            if (!vis[v] && g[u][v] != inf) {
                // 如果是像你那道题一样动态计算边权，就把 g[u][v] 换成计算公式即可
                if (g[u][v] < dist[v]) {
                    dist[v] = g[u][v];
                }
            }
        }
    }
    
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}