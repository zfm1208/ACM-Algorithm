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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    * 题解思路总结 - Codeforces 1076H Remove the Grail Tree
    * -------------------------------------------------------------------
    * 1. 核心题意 (Parity Game)
    * 删除条件：A[u] % 2 != Sum[u] % 2
    * 即：自身权值与“当前剩余”邻居权值和的奇偶性必须“相反” (一奇一偶)。
    *
    * 2. 关键观察 (The Impact of Removal)
    * 当删除节点 u 时，邻居 v 的 Sum[v] 会减去 A[u]。
    * - Case A (A[u] == 0): Sum[v] 减去偶数，奇偶性不变。
    * -> 结论：删除 0 节点是“无害”的，不会改变邻居原本能不能被删的状态。
    * - Case B (A[u] == 1): Sum[v] 减去奇数，奇偶性翻转。
    * -> 结论：删除 1 节点会“改变”邻居状态（可能把邻居从合法变非法，导致死锁）。
    *
    * 3. 贪心策略 (Greedy Strategy)
    * 基于“无害优先”原则：
    * 优先级 1：优先删 0 节点（安全牌，尽早腾位置）。
    * 优先级 2：若都是 0 或都是 1，优先删深层节点（Deepest First，维护树的连通性）。
    * 优先级 3：最后才删 1 节点（迫不得已才动它）。
    *
    * 4. 数据结构 (Implementation)
    * 使用 std::set<array<int,3>> st 维护“当前所有合法候选点”。
    * - 存储格式：{A[u], -deep[u], u}
    * - 排序原理：利用 set 字典序，A[u]=0 自然排在 A[u]=1 前面；
    * -deep[u] 越小（即 depth 越大）排在越前面。
    *
    * 5. 算法流程 (Topological Sort Variant)
    * Step 1: DFS 计算 depth，并将初始满足条件的点加入 set。
    * Step 2: while(!st.empty()) 取出堆顶 u，加入答案。
    * Step 3: 
    * - 优化：如果 A[u] == 0，直接 continue（因邻居状态不变，无需更新）。
    * - 如果 A[u] == 1，遍历邻居 v：
    * a. 若 v 原本满足条件（在 set 中），先 erase 踢出旧状态。
    * b. 更新 Sum[v] -= 1。
    * c. 若 v 新状态满足条件，再 insert 加入 set。
 */

 /*
    从叶子节点出发
 */
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] &= 1;
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> deep(n+1);
   
    auto dfs = [&](auto& self, int u, int fa) -> void {
        for(int v: adj[u]){
            if(v == fa) continue;
            deep[v] = deep[u] + 1;
            self(self,v,u);
        }
    };
    dfs(dfs,1,0);
    set<array<int,3>> st;
    vector<int> sum(n+1);
    for(int u = 1; u <= n; u++){
        for(int v: adj[u]){
            sum[u] += a[v];
        }
        if(a[u] % 2 != sum[u] % 2){
            st.insert({a[u],-deep[u],u});
        }
    }
    vector<int> vis(n+1);
    vector<int> ans;
    while(!st.empty()){
        auto [val,depth,u] = *st.begin();
        st.erase(st.begin());
        ans.pb(u);
        vis[u] = 1;
        if(val == 0) continue;
        for(int v: adj[u]){
            if(vis[v]) continue;
            if(st.count({a[v],-deep[v],v})){
                st.erase({a[v],-deep[v],v});
            }
            sum[v] -= a[u];
            if(sum[v] % 2 != a[v]){
                st.insert({a[v],-deep[v],v});
            }
        }
    }
    if(ans.size() < n){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int x: ans) cout << x << " ";
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}