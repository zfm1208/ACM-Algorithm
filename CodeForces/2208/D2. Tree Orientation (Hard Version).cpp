#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
// #define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void link(int x, int y){
        int fx = find(x), fy = find(y);
        if(fx != fy) fa[fx] = fy;
    }
};
void solve(){
    int n; cin >> n;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i++){
        string ss; cin >> ss;
        s[i] = " " + ss;
    }
    vector<int> siz(n+1);
    for(int u = 1; u <= n; u++){
        if(s[u][u] == '0'){
            cout << "NO" << endl;
            return;
        }
        for(int v = 1; v <= n; v++){
            if(u != v && s[u][v] == '1'){
                siz[u]++;
            }
        }
    }
    vector<int> P(n);
    iota(P.begin(), P.end(), 1);
    sort(P.begin(), P.end(), [&](int a, int b) {
        return siz[a] > siz[b]; 
    });

    vector<pii> ans;
    for(int u = 1; u <= n; u++){
        vector<int> vis(n + 1);
        for(int v : P){
            if(u == v || s[u][v] == '0') continue;
            if(vis[v]) continue;
            ans.pb({u, v});
            if(ans.size() >= n) {
                cout << "NO" << endl;
                return;
            }
            for(int x = 1; x <= n; x++){
                if(s[v][x] == '1'){
                    vis[x] = 1;
                }
            }
        }
    }
    if(ans.size() != n - 1) {
        cout << "NO" << endl;
        return;
    }
    DSU dsu(n);
    int cnt = n;
    for(auto [u,v] : ans){
        if(dsu.find(u) != dsu.find(v)){
            dsu.link(u,v);
            cnt--;
        }
    }
    if(cnt != 1){
        cout << "NO" << endl;
        return;
    }
    vector<vector<int>> adj(n + 1);
    for(auto [u, v] : ans) {
        adj[u].pb(v);
    }
    for(int u = 1; u <= n; u++){
        vector<int> vis1(n + 1);
        auto dfs = [&](auto self, int i) -> void {
            vis1[i] = 1;
            for(int v : adj[i]){
                if(!vis1[v]) self(self, v);
            }
        };
        dfs(dfs, u);
        for(int j = 1; j <= n; j++){
            if((vis1[j] == 1) != (s[u][j] == '1')){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(auto [u,v] : ans){
        cout << u << " " << v << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}