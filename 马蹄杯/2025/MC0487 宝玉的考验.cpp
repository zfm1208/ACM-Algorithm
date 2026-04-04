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
struct node{
    int d,id,state;
    bool operator<(const node& tp) const {
        return d > tp.d;
    };
};
void solve(){
    int n,m,k,t; cin >> n >> m >> k >> t;
    vector<vector<pii>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    unordered_map<int,int> mp;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        mp[x] = i;
    }
    vector<int> req(k);
    for(int i = 1; i <= t; i++){
        int x,y; cin >> x >> y;
        int u = mp[x];
        int v = mp[y];
        req[v] |= (1 << u);
    }
    vector<vector<int>> dist(n+1,vector<int>(1 << k, inf));
    priority_queue<node> pq;
    dist[1][0] = 0;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto [d,u,mask] = pq.top();
        pq.pop();
        if(d > dist[u][mask]) continue;
        for(auto [v,w] : adj[u]){
            int n_mask = mask;
            if(mp.find(v) != mp.end()){
                if((mask & req[mp[v]] )!= req[mp[v]]) continue;
                n_mask |= (1 << mp[v]);
            }
            if(dist[u][mask] + w < dist[v][n_mask]){
                dist[v][n_mask] = dist[u][mask] + w;
                pq.push({dist[v][n_mask], v, n_mask});
            }
        }
    }
    int ans = inf;
    for(int state = 0; state < (1 << k); state++){
        ans = min(ans, dist[n][state]);
    }
    if(ans == inf) cout << "impossible" << endl;
    else cout << ans << endl;
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