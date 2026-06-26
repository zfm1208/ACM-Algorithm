#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
struct node{
    int u,v,w;
};
void solve(){
    int n,m; cin >> n >> m;
    vii a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<node> e(m+1);
    vector<vector<pii>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        e[i] = {u, v, abs(a[u] - a[v])};
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    int pos = -1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            pos = i;
        }
    }
    if(pos == -1){
        cout << -1 << endl;
        return;
    }
    vector<int> dist(n+1, inf);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[pos] = 0;
    pq.push({0, pos});
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(d != dist[u]){
            continue;
        }
        for(auto [v, i] : adj[u]){
            if(dist[v] > dist[u] + e[i].w){
                dist[v] = dist[u] + e[i].w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] != a[i]){
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << e[i].w << endl;
    }
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