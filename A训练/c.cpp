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
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if(n <= 3) {
        cout << "NO" << endl;
        return;
    }

    int p = 0;
    bool ok = 0;
    auto dfs = [&] (auto &self, int u, int fa) -> void {
        if(ok == 1) return;
        if(adj[u].size() == 1){
            p = u;
            ok = 1;
            return;
        }
        for(auto v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);

    vector<int> dist(n+1);
    int st = p;
    auto dfs1 = [&] (auto &self, int u, int fa) -> void {
        for(auto v: adj[u]){
            if(v == fa) continue;
            dist[v] = dist[u] + 1;
            if(dist[v] > dist[st]) st = v;
            self(self, v, u);
        }
    };    
    dist[p] = 0;
    dfs1(dfs1, p, -1);


    for(int i = 1; i <= n; i++) dist[i] = 0;
    dist[st] = 0;

    int ed = st;
    auto dfs2 = [&] (auto &self, int u, int fa) -> void {
        for(auto v: adj[u]){
            if(v == fa) continue;
            dist[v] = dist[u] + 1;
            if(dist[v] > dist[ed]) ed = v;
            self(self, v, u);
        }
    };        
    dfs2(dfs2, st, -1);
    cout << st << " " << ed << endl;

    vector<int> ans;
    vector<int> siz(n+1);
    vector<int> w(n+1);
    auto dfs3 = [&](auto& self, int u, int fa) -> void {
        siz[u] = 1;
        for(auto v: adj[u]){
            if(v == fa) continue;
            self(self,v,u);
            siz[u] += siz[v];
            w[u] = max(w[u], siz[v]);
        }
        w[u] = max(w[u], n - siz[u]);
    };
    dfs3(dfs3, st, 0);
    int pos = 1;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cout << i << " " << w[i] << endl;
        if(w[i] == n/2){
            pos = i;
            break;
        }
    }
    cout << pos << endl;
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