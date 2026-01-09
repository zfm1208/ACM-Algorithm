#include <bits/stdc++.h>
using namespace std;
const int inf = 1e18;
const int N = 105;
int g[N][N];   // 邻接矩阵，g[u][v]表示节点u到节点v的边的权重
int dist[N];   // dist[i]表示从起点到节点i的最短距离
bool vis[N];   // vis[i]表示节点i是否已被访问
void dijkstra(int n){
    fill(dist, dist + N, inf);  // 初始化所有节点的最短距离为无穷大
    fill(vis, vis + N, false); // 初始化所有节点为未访问
    dist[1] = 0;               // 起点的最短距离设为0
    for(int t = 1; t <= n; ++t)// 循环n次，每次找到一个最短距离的节点
    {
        // 找到未访问的最小距离节点
        int u = -1;  // 初始化u为-1，表示尚未找到符合条件的节点
        for (int i = 1; i <= n; ++i) {  // 遍历所有节点0
            if (!vis[i] && (u == -1 || dist[i] < dist[u])) {  // 检查节点i是否未访问且距离更小
                u = i;  // 更新u为当前节点i
            }
        }
        // 如果所有节点都已访问或没有可达节点，则退出
        if (u == -1 || dist[u] == inf) break;
        vis[u] = true; // 标记节点u为已访问
        // 更新所有邻接节点的距离
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && g[u][i] != inf) { // 检查节点i是否未访问且u到i有边
                dist[i] = min(dist[i], dist[u] + g[u][i]);
            }
        }
    }
}
void solve(){
    int n, m,u, v, w;
    while(cin >> n >> m && (n != 0 || m != 0)){
        // 初始化邻接矩阵
        for(int i = 1; i <= n; ++i){
            fill(g[i], g[i] + n + 1, inf); // 将所有边的权重初始化为无穷大
            g[i][i] = 0; // 节点到自身的距离为0
        }
        // 读取边的信息并更新邻接矩阵
        while(m--){
            cin >> u >> v >> w;
            // 无向图
            g[u][v] = min(g[u][v], w);
            g[v][u] = min(g[v][u], w);
        }
        dijkstra(n); // 调用Dijkstra算法计算最短路径
        cout << dist[n] << endl; // 输出起点到节点n的最短距离
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}