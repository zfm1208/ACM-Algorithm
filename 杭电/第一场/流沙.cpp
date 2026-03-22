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
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> siz(n+1),sum(n+1);
    vector<int> dp(n+1);
    auto dfs =[&](auto& self, int u, int fa) -> void {
        siz[u] = 1;
        sum[u] = a[u];
        for(int v: adj[u]){
            if(v == fa) continue;
            self(self,v,u);
            siz[u] += siz[v];
            sum[u] += sum[v];
        }
        dp[u] = sum[u] / siz[u];
        for(int v: adj[u]){
            if(v == fa) continue;
            dp[u] = min(dp[u], dp[v]);
        }
    };
    dfs(dfs,1,0);
    for(int i = 1; i <= n; i++){
        cout << dp[i] << " \n"[i == n];
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