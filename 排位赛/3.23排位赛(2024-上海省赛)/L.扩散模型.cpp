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
const int N = 1e6, mod = 1e9+7, inf = 1e9 + 5;

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; i++){
        int op; cin >> op;
        for(int j = 1; j <= op; j++){
            int x; cin >> x;
            adj[i].pb(x);
        }
    }
    map<int,vector<int>> mp;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        mp[u].pb(v);
    } 
    vector<int> vis(n+1);
    for(int i = 1; i <= k; i++){
        int x; cin >> x;
        vis[x] = 1;
    }
    int ans = -1;
    vector<int> dp(n+1);
    auto dfs = [&](auto& self, int u, int cnt) -> void {
        if(adj[u].size() == 0){
            dp[u] = (vis[u] ? 0 : inf);
            return;
        }
        int cost1 = 0;
        for(int v: adj[u]){
            self(self,v,cnt);
            cost1 = cost1 + dp[v];
        }
        int cost2 = inf;
        if(mp.find(u) != mp.end()) for(auto v: mp[u]){
            cost2 = min(cost2,dp[v] + 1);
        }
        dp[u] = min(cost1,cost2);
    };
    dfs(dfs,1,0);
    ans = (dp[1] >= inf ? -1 : dp[1]);
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