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
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> dist(n+1);
    int st = 1;
    int mx = 0;
    auto dfs1 = [&](auto&self, int u, int fa) -> void {
        for(int v: adj[u]){
            if(v == fa) continue;
            dist[v] = dist[u] + 1;
            if(dist[v] > mx){
                mx = dist[v];
                st = v;
            }
            self(self, v, u);
        }
    };

    dfs1(dfs1, 1, 0);
    for(int i = 1; i <= n; i++) dist[i] = 0;
    mx = 0;
    int ed = st;
    vector<int> dad(n+1);
    auto dfs2 = [&](auto&self, int u, int fa) -> void {
        dad[u] = fa;
        for(int v: adj[u]){
            if(v == fa) continue;
            dist[v] = dist[u] + 1;
            if(dist[v] > mx){
                mx = dist[v];
                ed = v;
            }
            self(self, v, u);
        }
    };

    dfs2(dfs2, st, 0);
    // cout << st << " " << ed << endl;

    vector<int> path;
    int cur = ed;
    while(cur != 0){
        path.pb(cur);
        cur = dad[cur];
    }
    reverse(path.begin(),path.end());
    if(mx < 3){
        cout << "NO" << endl;
        return;
    }
    vector<int> vis(n+1);
    for(auto node: path) vis[node] = 1;
    cout << "YES" << endl;
    swap(path[0], path[1]);
    queue<int> q;
    for(int x: path){
       q.push(x);  
       cout << x << " ";
    } 
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;       
                cout << v << " ";  
                q.push(v);        
            }
        }
    }
    cout << endl;
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