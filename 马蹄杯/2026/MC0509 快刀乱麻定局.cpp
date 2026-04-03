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
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    vector<int> dist(n+1,-1);
    int cnt = 0;
    for(int i = 1; i <= k; i++){
        int x; cin >> x;
        q.push(x);
        dist[x] = 0;
        cnt++;
    }
    int ans = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans = max(ans, dist[u]);
        for(int v: adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
                cnt++;
            }
        }
    }
    if(cnt < n) cout << -1 << endl;
    else cout << ans << endl;
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