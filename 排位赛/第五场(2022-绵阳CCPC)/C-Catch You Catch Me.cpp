#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(n+1);
    vis[1] = 1;
    auto dfs = [&](auto& self, int u, int d) -> int {
        vis[u] = 1;
        int mx_dep = d;
        for(auto v: adj[u]){
            if(vis[v] == 1) continue;
            mx_dep = max(mx_dep, self(self,v,d+1));
        }
        return mx_dep;
    };
    int ans = 0;
    for(auto v: adj[1]){
        ans += dfs(dfs,v,1);
    }
    cout << ans << endl;
}
void solve2(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(n+1);
    vis[1] = 1;
    auto bfs = [&] (int st) -> int {
        queue<pii> q;
        q.push({st,1});
        vis[st] = 1;
        int mx_dep = 0;
        while(!q.empty()){
            auto [u,d] = q.front();
            q.pop();
            mx_dep = max(mx_dep,d);
            for(auto v: adj[u]){
                if(vis[v]) continue;
                vis[v] = 1;
                q.push({v,d+1});
            }
        }
        return mx_dep;
    };
    int ans = 0;
    for(auto v: adj[1]){
        ans += bfs(v);
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve2();
    }
    return 0;
}