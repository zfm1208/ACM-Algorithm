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
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> adj(n+1);
    for(int i = 2; i <= n; i++){
        int fa; cin >> fa;
        adj[fa].pb(i);
    }
    vector<int> siz(n+1),val(n+1);
    auto dfs = [&](auto& self, int u) -> void {
        siz[u] = 1;
        val[u] = a[u];
        for(int v: adj[u]){
            self(self,v);
            siz[u] += siz[v];
            val[u] += val[v];        
        }
    };
    dfs(dfs,1);
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(),adj[i].end(),[&](int x,int y){
            return val[x] * siz[y] < val[y] * siz[x];
        });
    }
    int cnt = 0,sum = 0;
    auto dfs1 = [&](auto& self, int u) -> void {
        sum += (++cnt) * a[u];
        for(int v: adj[u]){
            self(self,v);
        }
    };
    dfs1(dfs1,1);
    cout << sum << endl;
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