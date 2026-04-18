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
struct node {
    int id;
    int min_dist;
    int sum_dist;
    bool ok;
};
void solve(){
    int n,m,k,ds; 
    cin >> n >> m >> k >> ds;
    vector<vector<pii>> adj(n+m+1);
    auto get = [&](string s) -> int {
        if(s[0] == 'G'){
            return stoll(s.substr(1)) + n;
        }
        return stoll(s);
    };
    for(int i = 1; i <= k; i++){
        string s1,s2;
        cin >> s1 >> s2;
        int d; cin >> d;
        int u = get(s1), v = get(s2);
        adj[u].pb({v,d});
        adj[v].pb({u,d});
    }
    auto dijkstra = [&](int st) -> node {
        vector<int> dist(n+1+m,inf);
        dist[st] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,st});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto &[v,w]: adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        node cur = {st-n, inf, 0, 1};
        for(int i = 1; i <= n; i++){
            if(dist[i] > ds){
                cur.ok = 0;
                break;
            }
            cur.min_dist = min(cur.min_dist, dist[i]);
            cur.sum_dist += dist[i];
        }
        return cur;
    };
    vector<node> ans;
    for(int i = 1; i <= m; i++){
        node cur = dijkstra(i+n);
        if(cur.ok == 1) ans.pb(cur);
    }
    if(ans.empty()){
        cout << "No Solution";
        return;
    }
    sort(ans.begin(),ans.end(),[](node x, node y){
        if(x.min_dist != y.min_dist)
            return x.min_dist > y.min_dist;
        if(x.sum_dist != y.sum_dist)
            return x.sum_dist < y.sum_dist;
        return x.id < y.id;
    });
    node res = ans[0];
    cout << "G" << res.id << endl;
    double av = round(10.0 * res.sum_dist / n) / 10.0;
    cout << fixed << setprecision(1) << (double)res.min_dist << " " << fixed << setprecision(1) << av;
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