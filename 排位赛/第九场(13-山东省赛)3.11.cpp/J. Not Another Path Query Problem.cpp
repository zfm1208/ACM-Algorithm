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
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void link(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
        }
    }
};
struct node {
    int u,v,w;
};
void solve(){
    int n,m,q,V; 
    cin >> n >> m >> q >> V;
    vector<int> ts;
    ts.pb(V);
    for(int k = 0; k <= 60; k++){
        if(((V >> k) & 1) == 0){
            int cur = 0;
            for(int j = 60; j > k; j--){
                if((V >> j) & 1){
                    cur |= (1LL << j);
                }
            }
            cur |= (1LL << k);
            ts.pb(cur);
        }
    }
    int K = ts.size();
    vector<DSU> dsus(K,DSU(n));
    vector<node> e(m+1);
    for(int i = 1; i <= m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for(int i = 0; i < K; i++){
        for(int j = 1; j <= m; j++){
            if((e[j].w & ts[i]) == ts[i]){
                dsus[i].link(e[j].u, e[j].v);
            }
        }
    }
    while(q--){
        int u,v; cin >> u >> v;
        bool ok = 0;
        for(int i = 0; i < K; i++){
            if(dsus[i].find(u) == dsus[i].find(v)){
                ok = 1;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
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