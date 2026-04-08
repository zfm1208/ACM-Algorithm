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
    int n,m,st,ed;
    cin >> n >> m >> st >> ed;
    vector<int> a(n);
    rep(i,0,n-1) cin >> a[i];
    vector<vector<pii>> adj(n);
    for(int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<int> cnt(n),pre(n),team(n);
    auto dijkstra = [&] (int st) -> void {
        vector<int> dist(n,inf);
        dist[st] = 0;
        cnt[st] = 1;
        pre[st] = -1;
        team[st] = a[st];
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,st});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v,w]: adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    team[v] = team[u] + a[v];
                    cnt[v] = cnt[u];
                    pre[v] = u;
                    pq.push({dist[v], v});
                }else if(dist[u] + w == dist[v]){
                    cnt[v] += cnt[u];
                    if(team[v] < team[u] + a[v]){
                        team[v] = team[u] + a[v];
                        pre[v] = u;
                        // pq.push({dist[v], v});
                    }
                }
            }
        }
    };
    dijkstra(st);
    cout << cnt[ed] << " " << team[ed] << endl;
    vector<int> ans;
    ans.pb(ed);
    int op = ed;
    while(op){
        op = pre[op];
        if(op == -1) break;
        ans.pb(op);
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
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