#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;  // 定义模数1
const int mod2 = 998244353;  // 定义模数2
const int inf = 1e18;  // 定义无穷大
const int N = 2e5 + 5;  // 定义最大节点数
int n, m, ans;  // n: 节点数, m: 边数, ans: 最小生成树的边权之和
struct node {
    int v;  // 边的终点
    int val;  // 边的权重
};
bool operator< (node a, node b) {
    return a.val > b.val;  // 重载小于运算符，用于优先队列的排序
};
priority_queue<node> pq[N];  // 每个节点的优先队列，存储与该节点相连的边
bool vis[N];  // 标记数组，记录节点是否已经被访问过

void solve() {
    cin >> n >> m;  // 输入节点数n和边数m
    int u, v, val;
    while (m--) {
        cin >> u >> v >> val;  // 输入每条边的两个端点和权重
        pq[u].push({v, val});  // 将边加入节点u的优先队列
        pq[v].push({u, val});  // 将边加入节点v的优先队列
    }
    vis[1] = 1;  // 从节点1开始，标记为已访问
    for (int i = 1; i < n; i++) {  // 循环n-1次，每次找到一条最小边
        int min_val = mod1, min_v;  // min_val: 当前最小边的权重，min_v: 当前最小边的起点
        for (int j = 1; j <= n; j++) {  // 遍历所有节点
            if (!vis[j]) continue;  // 如果节点j未被访问过，跳过
            while (!pq[j].empty() && vis[pq[j].top().v]) pq[j].pop();  // 弹出已经访问过的节点
            if (pq[j].empty() || pq[j].top().val >= min_val) continue;  // 如果队列为空或当前边权重大于最小权重，跳过
            min_val = pq[j].top().val;  // 更新最小权重
            min_v = j;  // 更新最小边的起点
        }
        if (min_val == mod1) {  // 如果最小权重未被更新，说明图不连通
            cout << "orz" << endl;
            return;
        }
        vis[pq[min_v].top().v] = 1;  // 标记最小边的终点为已访问
        pq[min_v].pop();  // 弹出这条边
        ans += min_val;  // 将最小边的权重加入答案
    }
    cout << ans << endl;  // 输出最小生成树的边权之和
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}