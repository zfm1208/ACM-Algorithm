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

void solve(){
    int n; cin >> n;
    vector<vii> adj(n+1);
    vii gen;
    for(int i = 1; i <= n; i++){
        int r; cin >> r;
        if(r) adj[r].push_back(i);
        else gen.push_back(i);
    }
    vector<array<int,20>> up(n+1);
    vii siz(n+1), big(n+1), dep(n+1), cnt(n+1);
    auto dfs = [&](auto&self, int u, int fa) -> void  {
        siz[u] = 1;
        big[u] = 0;
        dep[u] = dep[fa] + 1;
        up[u][0] = fa;
        for(int i = 1; i < 20; i++){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for(auto v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(big[u] == 0 || siz[v] > siz[big[u]]){
                big[u] = v;
            }
        }
    };
    for(int x: gen) dfs(dfs, x,  0);
    auto get  = [&](int u, int k) -> int {
        for(int i = 0;i < 20; i++){
            if((k >> i) & 1LL) u = up[u][i];
        }
        return u;
    };
    int m; cin >> m;
    vii ans(m+1);
    vector<vector<pii>> qs(n+1);
    for(int i = 1; i <= m; i++){
        int v,p; cin >> v >> p;
        int gt = get(v, p);
        if(gt == 0) ans[i] = 0;
        else qs[gt].push_back({dep[v], i});
    }
    auto update = [&] (auto& self, int u, int fa, int skip, int op) -> void {
        if(op == 1){
            cnt[dep[u]]++;
        }else{  
            cnt[dep[u]]--;
        }
        for(int v: adj[u]){
            if(v == fa || v == skip) continue;
            self(self, v, u, skip, op);
        }
    };

    auto dsu = [&](auto& self, int u, int fa, int ok) -> void {
        for(int v: adj[u]){
            if(v == fa || v == big[u]) continue;
            self(self, v, u, 0);
        }
        if(big[u] != 0) self(self, big[u], u, 1);
        for(int v : adj[u]){
            if(v == fa || v == big[u])  continue;
            update(update, v, u, 0, 1);
        }
        cnt[dep[u]]++;
        for(auto &[r, id] : qs[u]){
            ans[id] = cnt[r] - 1;
        }
        if(ok == 0) {update(update, u, fa,  0, -1);}
    };

    for(int x: gen) dsu(dsu, x, 0, 0);
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " \n"[i == m];
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