#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve() {
    int n;  cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> siz(n + 1, 0);      // siz[u] 表示以 u 为根的子树大小
    vector<int> w(n + 1, 0);  // w[u] 表示删除 u 后，最大连通块的大小
    vector<int> ans;          // 存储重心的数组（树的重心最多只有两个）
    int mn = inf;          // 记录全局最小的“最大连通块大小”

    auto dfs = [&](auto& self, int u, int fa) -> void {
        siz[u] = 1;     // 自己本身算 1 个节点
        w[u] = 0; // 初始化最大连通块大小

        for(int v : adj[u]){
            if (v == fa) continue; // 不回头搜父节点
            self(self, v, u); // 递归遍历子树
            siz[u] += siz[v];   // 累加子树的大小
            // 考察向下的各个子树，更新删除 u 后的最大连通块大小
            w[u] = max(w[u], siz[v]); 
        }

        // 考察向上的那一部分连通块（整棵树的大小 n 减去以 u 为根的子树大小）
        w[u] = max(w[u], n - siz[u]);

        // 维护全局最小值，寻找重心
        if (w[u] < mn) {
            mn = w[u];
            ans.clear(); // 发现了更优的解，清空之前的记录
            ans.push_back(u);
        } else if (w[u] == mn) {
            ans.push_back(u); // 如果有多个节点满足最小条件，一并记录（最多两个）
        }
    };

    // 从任意节点（例如 1 号节点）开始搜索即可
    dfs(dfs, 1, 0);

    // 输出结果
    cout << "重心的个数: " << ans.size() << "\n";
    cout << "重心的节点编号: ";
    for (int c : ans) {
        cout << c << " ";
    }
    cout << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}