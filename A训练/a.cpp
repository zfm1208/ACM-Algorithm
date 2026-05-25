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
struct BIT {
    int n;
    vector<int> tr;
    BIT(int _n) {
        n = _n;
        tr.resize(_n + 1, 0);
    };
    int low_bit(int x) {return x & (-x);}
    void add(int x, int c) {
        if(x <= 0) return;
        for(int i = x; i <= n; i += low_bit(i)) tr[i] += c;
    }

    int query(int x){
        int res = 0;
        for(int i = x; i > 0; i -= low_bit(i)){
            res += tr[i];
        }
        return res;
    }
    
    int query(int l, int r){
        if(l > r) return 0;
        return query(r) - query(l - 1);
    }
};
void solve(){
    int n,m; cin >> n >> m;
    vii col(n+1);
    rep(i,1,n) cin >> col[i];
    vector<vii> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<pii>> qs(n+1);
    for(int i = 1; i <= m; i++){
        int u,k; cin >> u >> k;
        qs[u].push_back({k,i});
    }
    vii big(n+1), siz(n+1);
    auto dfs = [&](auto& self, int u, int fa) -> void {
        siz[u] = 1;
        big[u] = 0;
        for(int v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(big[u] == 0 || siz[v] > siz[big[u]]){
                big[u] = v;
            }
        }
    };
    dfs(dfs, 1, 0);
    vii cnt(100005), ans(m+1);
    BIT bit(n+5);
    auto update =[&](auto& self, int u, int fa, int skip, int op) -> void {
        int c = col[u];
        if(op == 1){
            if(cnt[c] > 0) bit.add(cnt[c], -1);
            cnt[c]++;
            bit.add(cnt[c], 1);
        }else if(op == -1){
            bit.add(cnt[c], -1);
            cnt[c]--;
            if(cnt[c] > 0) bit.add(cnt[c], 1);
        }

        for(int v: adj[u]){
            if(v == fa || v == skip) continue;
            self(self, v, u, skip, op);
        }

    };
    auto dfs1 = [&](auto& self, int u, int fa, int ok) -> void {
        for(int v: adj[u]){
            if(v == fa || v == big[u]) continue;
            self(self, v, u, 0);
        }
        if(big[u] != 0) self(self, big[u], u, 1);
        for(int v: adj[u]){
            if(v == fa || v == big[u]) continue;
            update(update, v, u, 0, 1);
        }

        int c = col[u];
        if(cnt[c]) bit.add(cnt[c], -1);
        cnt[c]++;
        bit.add(cnt[c], 1);

        for(auto [k, id]: qs[u]){
            if(k <= n) ans[id] = bit.query(k, n);
            else ans[id] = 0;
        }
        if(ok == 0) update(update, u, fa, 0, -1);
    };

    dfs1(dfs1, 1, 0, 0);
    rep(i, 1, m) cout << ans[i] << endl;
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