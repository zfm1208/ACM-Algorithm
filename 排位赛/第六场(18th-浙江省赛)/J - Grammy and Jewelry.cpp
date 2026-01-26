#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7, inf = 1e18;
#define pb push_back
// 0.5s 
// n,m,t <= 3000 
// 可能有自环和重边
// 每次只能拿一件
// 奇数时间t其实和t-1等效
// 算1到其他地方的最短时间，然后dp
void solve(){
    int n,m,t; cin >> n >> m >> t;
    vector<int> a(n+2);
    for(int i = 2; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> dist(n+1,inf);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v :adj[u]){
            if(dist[v] == inf){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    vector<int> dp(t+1);
    for(int i = 2; i <= n; i++){
        if(dist[i] == inf) continue;
        if(2 * dist[i] > t) continue;
        for(int j = 2 * dist[i]; j <= t; j++){
            dp[j] = max(dp[j], dp[j-2*dist[i]] + a[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= t; i++){
        ans = max(ans,dp[i]);
        cout << ans << " \n"[i == t];
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}