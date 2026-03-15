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
    vector<int> a(n+1), val;
    rep(i,1,n) cin >> a[i],val.pb(a[i]);
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    for(int i = 1; i <= n; i++){
        a[i] = (lower_bound(val.begin(),val.end(),a[i]) - val.begin()) + 1;
    }
    vector<int> ans(n+1);
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    int cnt = 0;
    vector<int> mp(n+1);
    auto dfs = [&](auto& self, int u, int fa) -> void {
        mp[a[u]]++;
        if(mp[a[u]] == 2) cnt++;
        ans[u] = (cnt > 0 ? 1 : 0);
        for(int v: adj[u]) if(v != fa)
            self(self,v,u);
        if(mp[a[u]] == 2) cnt--;
        mp[a[u]]--;
    };
    dfs(dfs,1,0);

    rep(i,1,n) cout << (ans[i] == 1 ? "Yes" : "No") << endl;
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