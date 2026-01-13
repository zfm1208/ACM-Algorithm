#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10,mod = 1e9+7,inf = 1e18;
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)

void zfm(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> e(k+1); // k条出口
    rep(i,1,k) cin >> e[i];
    vector<int> d(n+1); // d[i] : 第i个点怪的个数
    rep(i,1,n) cin >> d[i];
    vector<vector<pii>> adj(n+1); 
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist(n+1,inf);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i = 1; i <= k; i++){
        dist[e[i]] = 0;
        for(auto [v,w] : adj[e[i]]){
            pq.push({w,v});
        }
    }
    while(!pq.empty()){
        auto [c,u] = pq.top();
        pq.pop();
        if(dist[u] != inf) continue;
        if(c > dist[u]){
            continue;
        }
        if(d[u]) d[u]--;
        else{
            dist[u] = c;
            for(auto [v,w] : adj[u]){
                if(dist[v] == inf){
                    pq.push({dist[u]+w,v});
                }
            }
        }
    }
    cout << (dist[1] == inf ? -1 : dist[1]) << '\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        zfm();
    }
    return 0;
}