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

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> l,r;
    l.pb(0),r.pb(0);
    for(int i = 1; i <= n; i++){
        if(3 * a[i] > m) l.pb(a[i]);
        else r.pb(a[i]);
    }
    int nL = l.size() - 1; // 大数
    int nR = r.size() - 1; // 小数
    vector<vector<int>> adj(nL + 1);
    for (int i = 1; i <= nL; i++) {
        for (int j = 1; j <= nR; j++) {
            if (l[i] % r[j] == 0 && l[i] * 2 + r[j] <= m) {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> match(nR + 1, 0);// match[v] 记录右部节点 v 匹配到的左部节点编号
    vector<int> vis(nR + 1, 0);// 标记在单次 DFS 中右部节点是否被访问过
    
    auto dfs = [&](auto& self, int u, int tag) -> bool {
        for(int v : adj[u]){
            if(vis[v] == tag) continue;
            vis[v] = tag;
            // 如果 v 没对象，或者 v 的对象能找到“备胎”
            if (match[v] == 0 || self(self, match[v], tag)) {
                match[v] = u;// 匹配成功
                return true;
            }
        }
        return false;
    };
    
    int cnt = 0;
    for (int i = 1; i <= nL; i++) {
        if(dfs(dfs, i, i)) cnt++;// 每找到一条增广路，匹配数 +1
    }
    if(cnt < nL){
        cout << -1 << "\n";
        return;
    }
    vector<pii> ans;
    vector<int> vis1(nR + 1, false);
    for (int j = 1; j <= nR; j++) {
        if (match[j] != 0) {
            int u = match[j]; 
            ans.push_back({l[u] * 2 + r[j],l[u] + r[j]});
            vis1[j] = true;
        }
    }
    for (int j = 1; j <= nR; j++) {
        if (!vis1[j]) {
            ans.push_back({r[j] * 3, r[j] * 2});
        }
    }
    cout << ans.size() << "\n";
    for (auto &[x,y] : ans) {
        cout << x << " " << y << "\n";
    }
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