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
    auto ys = [&] (string s) -> int {
        if(s[0] == 'G'){
            return stoi(s.substr(1)) + n;
        }
        return stoi(s);
    };
    for(int i = 1; i <= k; i++){
        string s1,s2; int w;
        cin >> s1 >> s2 >> w;
        int u = ys(s1);
        int v = ys(s2);
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    auto dijkstra = [&] (int st) -> node {
        vector<int> dist(n+m+1,inf);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[st] = 0;
        pq.push({0, st});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for(auto& [v,w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        node res = {st - n, inf, 0, true};
        for(int i = 1; i <= n; i++){
            if(dist[i] > ds){
                res.ok = false; 
                break;
            }
            res.min_dist = min(res.min_dist, dist[i]);
            res.sum_dist += dist[i];
        }
        return res;
    };
    vector<node> ans;

    for(int i = 1; i <= m; i++){
        node curr = dijkstra(n + i);
        if(curr.ok) ans.pb(curr);
    }
    if(ans.empty()){
        cout << "No Solution" << endl;
        return;
    }
    sort(ans.begin(), ans.end(), [](const node& a, const node& b) {
        if (a.min_dist != b.min_dist) 
            return a.min_dist > b.min_dist; 
        if (a.sum_dist != b.sum_dist) 
            return a.sum_dist < b.sum_dist; 
        return a.id < b.id;                
    });
    node best = ans[0];

    double av = round((double)best.sum_dist / n * 10.0) / 10.0;

    cout << "G" << best.id << '\n';
    cout << fixed << setprecision(1) << (double)best.min_dist << " " << av << endl;
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