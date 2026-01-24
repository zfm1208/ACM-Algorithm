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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    *代码不对，没做出来
*/
void solve(){
    // *边找边更新是不对的，因为，居民不一定要跑到安全区，只要能躲过当前的锤子就行。
    int n,m,q; cin >> n >> m >> q;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<vector<pii>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<int> b(q+1);
    for(int i = 1; i <= q; i++){
        cin >> b[i];
    }
    vector<int> dist(n+1); // dist[i]: 从当前时刻往后，住在i的居民存活所需的最小代价
    int ans = 0;
    for(int t = q; t >= 1; t--){
        int u = b[t];
        int cost = inf;
        for(auto [v,w] : adj[u]){
            if(dist[v] != inf){
                cost = min(cost, w + dist[v]);
            }
        }
        dist[u] = cost;
    }
    for(int i = 1; i <= n; i++){
        ans = (ans + (a[i] % mod) * (dist[i] % mod) % mod) % mod;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}