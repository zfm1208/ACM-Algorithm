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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int n,k;
vector<int> g[N];
int siz[N];
int ans[N];
bool vis[N]; // vis[i] = 1: 该点是上升点
int cnt;
void dfs(int u, int fa){
    siz[u] = 1;
    for(auto v: g[u]){
        if(v == fa) continue;
        dfs(v,u);
        siz[u] += siz[v];
    }
}
//后序遍历 (子 -> 父)
void dfs0(int u, int fa){
    for(auto v: g[u]){
        if(v == fa) continue;
        dfs0(v,u);
    }
    if(vis[u] == 0) ans[u] = ++cnt;
}
//先序遍历 (父 -> 子)
void dfs1(int u, int fa){
    if(vis[u] == 1) ans[u] = ++cnt;
    for(auto v: g[u]){
        if(v == fa) continue;
        dfs1(v,u);
    }
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(k < n){cout << "No" << endl;return;}
    dfs(1,0);
    int dif = k-n;
    vector<pii>v;
    // 结点1 是根节点
    for(int i = 2; i <= n; i++){
        v.pb({siz[i],i});
    }
    sort(v.rbegin(),v.rend());
    for(auto[sz,p] : v){
        if(dif >= sz){
            dif -= sz;
            vis[p] = 1;
        }
    }
    if(dif){cout << "No" << endl;return;}
    cout << "Yes" << endl;
    // 先填写vis=0的点,再填vis=1的点
    dfs0(1,0);
    dfs1(1,0);
    rep(i,1,n) cout << ans[i] << " \n"[i==n];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}