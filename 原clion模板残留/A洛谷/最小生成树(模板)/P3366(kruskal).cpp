// NO ac!!!!!!!!!
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5 + 5; // 最大节点数
const int M = 2e5 + 5; // 最大边数
int n, m; // n: 节点数, m: 边数
int parent[N]; // 并查集数组，用于判断是否形成环
struct Edge {
    int u, v, w; // 边的两个端点和权重
    bool operator<(const Edge& other) const {
        return w < other.w; // 按边权重从小到大排序
    }
} edges[M];
// 并查集的查找函数，带路径压缩
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 路径压缩
    }
    return parent[x];
}
// 并查集的合并函数
bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return false; // 如果两个节点已经在同一个集合中，合并失败
    parent[rootX] = rootY; // 合并两个集合
    return true;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w; // 输入每条边
    }
    // 初始化并查集
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    // 按边权重从小到大排序
    sort(edges + 1, edges + m + 1);
    int ans = 0; // 最小生成树的边权之和
    int cnt = 0; // 已选边的数量
    // 遍历所有边
    for (int i = 1; i <= m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (unite(u, v)) { // 如果边的两个端点不在同一个集合中
            ans += w; // 将边权加入答案
            cnt++; // 已选边数加1
            if (cnt == n - 1) break; // 如果已选边数达到 n-1，最小生成树构建完成
        }
    }
    if (cnt == n - 1) { // 如果成功选择了 n-1 条边，输出最小生成树的边权之和
        cout << ans << endl;
    } else { // 否则，图不连通
        cout << "orz" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}