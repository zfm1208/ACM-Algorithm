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
    vector<vector<pii>> adj(n+1);
    for(int i = 1; i <= n - 1; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<int> vis(n+1);
    rep(i,1,m){
        int x; cin >> x;
        vis[x] = 1;
    }
    int ans = 0;
    // dfs(v,u) : 返回的是以v为根的所有目标，一共需要从v的父节点u拉下来多少条路径
    auto dfs = [&](auto&self, int u, int fa) -> int {
        int res = 0;
        if(u != 1 && adj[u].size() == 1) return 1;
        for(auto [v,w]: adj[u]){
            if(v == fa) continue;
            int cnt = self(self, v, u);
            ans += (cnt - 1) * w;
            res += cnt;
        }
        if(vis[u] == 1) return 1;
        return res;
    };
    dfs(dfs, 1, 0);
    cout << ans << endl;
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