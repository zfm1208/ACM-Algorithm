#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int dep[N], fa[N][20];
vector<vii> adj;
void dfs_lca(int u, int p) {
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    for(int i = 1; i <= 18; i++){
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }
    for(int v: adj[u]){
        if(v == p) continue;
        dfs_lca(v, u);
    }
}

int get_lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 18; i >= 0; i--){
        if(dep[fa[u][i]] >= dep[v]){
            u = fa[u][i];
        }
    }
    if(u == v) return u;

    for(int i = 18; i >= 0; i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
void solve(){
    int n,m; cin >> n >> m;
    adj.resize(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_lca(1, 0);
    vector<vector<pii>> dif(n+1);
    for(int i = 1; i <= m; i++){
        int u,v,z; cin >> u >> v >> z;
        int lca = get_lca(u,v);
        dif[u].push_back({z, 1});
        dif[v].push_back({z, 1});
        dif[lca].push_back({z, -1});
        if(fa[lca][0] != 0) dif[fa[lca][0]].push_back({z, -1});
    }
    vii siz(n+1), big(n+1);
    auto dfs = [&](auto& self, int u, int p) -> void  {
        siz[u] = 1;
        big[u] = 0;
        for(int v: adj[u]){
            if(v == p) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(big[u] == 0 || siz[v] > siz[big[u]]){
                big[u] = v;
            }
        }
    };
    dfs(dfs, 1, 0);
    vii ans(n+1), cnt(N);
    set<pii> st; // [数量, 种类]
    auto modify = [&] (int z, int x) -> void {
        if(cnt[z] > 0) st.erase({cnt[z], -z});
        cnt[z] += x;
        if(cnt[z] > 0) st.insert({cnt[z], -z});
    };

    auto update = [&](auto&self, int u, int p, int skip, int op) -> void {
        for(auto [z, x]: dif[u]){
            modify(z, x * op);
        }
        for(int v: adj[u]){
            if(v == p || v == skip) continue;
            self(self, v, u, skip, op);
        }
    };

    auto dsu = [&](auto& self, int u, int p, int ok) -> void {
        for(int v: adj[u]){
            if(v == p || v == big[u]) continue;
            self(self, v, u, 0);
        }
        if(big[u] != 0) self(self, big[u], u, 1);
        for(int v: adj[u]){
            if(v == p || v == big[u]) continue;
            update(update, v, u, 0, 1);
        }

        for(auto[z, x]: dif[u]){
            modify(z, x);
        }

        if(st.empty() || st.rbegin() -> first == 0){
            ans[u] = 0;
        }else{
            ans[u] = -(st.rbegin() -> second);
        }

        if(ok == 0) update(update, u, p, 0, -1);
    };

    dsu(dsu, 1, 0, 0);
    rep(i,1,n) cout << ans[i] << endl;
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