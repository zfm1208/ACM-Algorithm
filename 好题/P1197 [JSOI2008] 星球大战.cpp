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

struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n);
        iota(fa.begin(),fa.end(),0);
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    
    bool link(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
            return true;
        }else {
            return false;
        }
    }
};
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int k; cin >> k;
    vector<int> tar(k);
    vector<int> vis(n);
    for(auto &x : tar){
        cin >> x;
        vis[x] = 1;
    }
    DSU dsu(n);
    int cnt = n-k;
    for(int u = 0; u < n; u++){
        if(vis[u]) continue;
        for(int v: adj[u]){
            if(vis[v]) continue;
            if(dsu.link(u,v)) cnt--;
        }
    }
    vector<int> ans(k+1);
    ans[k] = cnt;
    for(int i = k-1; i >= 0; i--){
        int u = tar[i];
        vis[u] = 0;
        cnt++;
        for(int v: adj[u]){
            if(vis[v]) continue;
            if(dsu.link(u,v)){
                cnt--;
            }
        }
        ans[i] = cnt;
    }
    for(int x: ans) cout << x << endl;
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

