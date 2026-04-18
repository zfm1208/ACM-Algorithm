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
int fa[N];
bool vis[N];
struct node {
    int u,v;
};
vector<node> e;
int n,m;
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) {
        fa[fx] = fy;
    }
}
int count() {
    for(int i = 0; i < n; i++) fa[i] = i;
    for(int i = 0; i < e.size(); i++){
        auto [u,v] = e[i];
        if(vis[u] && vis[v]) merge(u,v);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] && fa[i] == i) cnt++;
    }
    return cnt;
}
void solve(){
    cin >> n >> m;
    rep(i,0,n-1) vis[i] = 1;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        e.push_back({u,v});
    }
    int cnt = count();
    int k; cin >> k;
    int zha = 0;
    while(k--){
        int ct; cin >> ct;
        vis[ct] = 0;
        zha++;
        int cc = count();
        if(cc > cnt){
            cout << "Red Alert: City " << ct << " is lost!\n";
        } else {
            cout << "City " << ct << " is lost.\n";
        }
        cnt = cc;
        if(zha == n){
            cout << "Game Over.\n";
        }
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