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
//https://www.matiji.net/exam/brushquestion/65/4693/305EE97B0D5E361DE6A28CD18C929AF0

/*
 * 题目：MC0465 - 夺取山寨
 * * 【核心解题思路】
 * 1. 题意转化：将 0 到 n-1 这 n 个数字不重复地分配给 n 个节点，求整棵树所有子树 mex(u) 之和的最大值。
 * * 2. 关键性质（权值 0 的唯一性）：
 * 因为数字不能重复，所以整棵树中权值为 0 的节点有且仅有一个。
 * 对于任意一个子树，如果它内部没有包含这个 0，那么它缺失的最小自然数必然是 0，即 mex 值为 0。
 * * 3. 路径推导：
 * 全树只有包含了 0 的子树，其 mex 才可能大于 0。
 * 在树结构中，包含某个特定节点（那个放了 0 的节点）的所有节点，刚好构成了一条从根节点（节点 1）出发向下的单链路径。
 * 这意味着：只有在这条路径上的点，对最终答案才有贡献；路径之外的节点 mex 全部是 0。
 * * 4. 贪心策略：
 * 对于路径上的任意节点 u，我们只要把 0 到 siz[u]-1 这些数字全部分配到它的子树内部，
 * 它的 mex(u) 就能达到理论最大值——也就是它的子树大小 siz[u]。
 * * 5. 树形 DP 转化：
 * 问题最终转化为：寻找一条从根节点向下的路径，使得路径上所有节点的子树大小 (siz) 之和最大。
 * * 【状态定义与转移】
 * - siz[u] : 以 u 为根的子树节点总数。
 * - dp[u]  : 以 u 为根的子树中，选择一条包含 0 的向下路径所能获得的最大 mex 总和。
 * * 转移方程：dp[u] = siz[u] + max(dp[v])  (v 为 u 的子节点)
 * 最终答案：dp[1]
 */
void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> siz(n+1),dp(n+1);
    auto dfs = [&] (auto &self, int u, int fa) -> void {
        dp[u] = siz[u] = 1;
        for(int v: adj[u]){
            if(v == fa) continue;
            self(self,v,u);
            siz[u] += siz[v];
        }
        for(auto v: adj[u]){
            if(v == fa) continue;
            dp[u] = max(dp[u], dp[v] + siz[u]);
        }
    };
    dfs(dfs,1,0);
    cout << dp[1] << endl;
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