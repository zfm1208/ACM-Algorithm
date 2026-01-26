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
    【核心思想】
    1. 删除偶数点(0)不会改变它邻居的 S 值的奇偶性。
       -> 偶数点是'被动'的，它是无害的。只要条件满足，随时可以删，删了也不会卡死别人。
    2. 删除奇数点(1)会翻转它邻居的 S 值奇偶性（奇变偶，偶变奇）。
       -> 奇数点是'主动'的，这是解题的钥匙，用来解锁那些原本卡住的点。

    【删除条件】
    1. 对于偶数点(0)：
       需要邻居之和为奇数 -> 即需要有【奇数个】权值为 '1' 的邻居。
       策略：一旦偶数点满足条件，立刻把它加入删除队列（预处理或顺带删除）。

    2. 对于奇数点(1)：
       需要邻居之和为偶数 -> 即需要有【偶数个】权值为 '1' 的邻居。
       策略：我们自底向上处理，如果一个奇数点满足条件，主动删掉它，利用'连锁反应'解锁周围的点。

    【算法流程】
    <1>: 预处理和排序
        - 以 1 为根节点 DFS，建立父子关系，计算深度。
        - 统计每个节点 u 有多少个权值为 1 的邻居，记为 o[u]。
        - 将所有节点按照深度由大到小排序 (确保自底向上，优先处理依赖少的叶子)。

    <2>: 先处理原本就能删的偶数点 (清理战场)
        - 遍历所有点，如果 v 是偶数(0)，且 o[v] 是【奇数】，则标记为可删除并加入答案。
          (因为删 0 不影响大局，先删掉可以简化后续状态)

    <3>: 自底向上处理奇数点 (主动出击)
        - 按照深度从深到浅遍历节点 u。
        - 如果 u 是奇数(1)，且 o[u] 是【偶数】，那么执行 kill(u) 函数。

    <4>: kill(u) 函数 (处理连锁反应)
        - 标记 u 已删除，加入答案。
        - 遍历 u 的所有未删除邻居 v (包括父亲和孩子)：
          a. 更新邻居状态：o[v]-- (因为移除了一个 1)。
          b. 顺手牵羊：如果邻居 v 是偶数(0)，且 o[v] 变成了奇数(满足条件)，顺便递归或直接删除 v。
          c. 乘胜追击：如果邻居 v 是子节点且是奇数(1)，且 o[v] 变成了偶数(满足条件)，递归调用 kill(v)。
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
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    } 
    vector<int> dad(n+1),deep(n+1);
    vector<vector<int>> child(n+1);
    auto build = [&] (auto& self, int u, int fa, int d) -> void {
        dad[u] = fa;
        deep[u] = d;
        for(int v: adj[u]){
            if(v == fa) continue;
            child[u].pb(v);
            self(self, v, u, d+1);
        }
    };
    build(build, 1, 0, 0);
    vector<int> odd(n+1);
    for(int u = 1; u <= n; u++){
        for(int v: adj[u]){
            if(a[v]&1) odd[u]++;
        }
    }
    vector<int> ans;
    vector<int> vis(n+1);
    for(int i = 1; i <= n; i++){
        if(a[i] == 0 && odd[i] & 1){
            vis[i] = 1;
            ans.pb(i);
        }
    }
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),1);
    sort(ord.begin(),ord.end(),[&](int x, int y){
        return deep[x] > deep[y];
    });
    auto kill = [&](auto& self, int u) -> void {
        if(vis[u]) return;
        vis[u] = 1;
        ans.pb(u);
        for(auto v: adj[u]){
            if(vis[v]) continue;
            odd[v]--;
            if(a[v] % 2 == 0 && odd[v] & 1){
                vis[v] = 1;
                ans.pb(u);
            }
        }
        for(int v: child[u]){
            if(!vis[v] && a[v] == 1 && (odd[v] % 2 == 0)){
                self(self,v);
            }
        }
    };
    for(auto u : ord){
        if(a[u] == 1 && vis[u] == 0 && odd[u] % 2 == 0){
            kill(kill,u);
        }
    }
    if(ans.size() == n){
        cout << "YES" << endl;
        for(int x: ans) cout << x << " ";
        cout << endl;
    }else{
        cout << "NO" << endl;
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