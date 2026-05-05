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
    vector<vector<int>> adj(n+1);vector<int> du(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if(cn == n-1){
        cout << "NO" << endl;
        return;        
    }
    if(n <= 3) {
        cout << "NO" << endl;
        return;
    }
    
    
    cout << "YES" << endl;
    vector<int> w(n+1);
    int cnt = 0;
    auto dfs = [&] (auto &self, int u, int fa) -> void {
        cnt++;
        for(auto v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
        }
    };
    for(int i = 1; i <= n; i++){
        w[i] = 0;
        for(int v: adj[i]){
            cnt = 0;
            dfs(dfs, v, i);
            w[i] = max(w[i], cnt);
        }
    }
    int pos = 0;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        // cout << i << " " << w[i] << endl;
        if(w[i] == n/2){
            pos = i;
            break;
        }
    }
     auto dfs1 = [&] (auto &self, int u, int fa) -> void {
        cout << u << " ";
        for(auto v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
        }
    };   
    dfs1(dfs1, pos, 0);

    // vector<int> vis(n+1);
    // queue<int> q;
    // q.push(pos);
    // while(q.size()){
    //     int u = q.front();
    //     q.pop();
    //     if(vis[u] == 1) continue;
    //     vis[u] = 1;
    //     cout << u << " ";
    //     for(auto v: adj[u]){
    //         if(vis[v] == 0) q.push(v);
    //     }
    // }

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