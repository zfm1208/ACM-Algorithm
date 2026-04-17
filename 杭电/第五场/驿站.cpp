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
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
    } 
    vector<int> dist(n+1, inf);
    dist[1] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({1,1}); // 风险，编号
    while(!pq.empty()){
        auto [fx,u] = pq.top();
        pq.pop();
        if(fx > dist[u]) continue;
        for(int v: adj[u]){
            int mx = max(v,fx);
            if(mx < dist[v]){
                dist[v] = mx;
                pq.push({mx,v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] == inf){
            cout << -1 << " \n"[i==n];
        }else{
            cout << dist[i] << " \n"[i==n];
        }
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