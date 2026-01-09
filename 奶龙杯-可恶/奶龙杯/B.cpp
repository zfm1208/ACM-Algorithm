#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 2e5 + 7, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
vector<int> a[N];
int ans = 1;
bool vis[N];
void dfs(int u,int fa){
    for(auto &v: a[u]){
        if(v == fa || vis[v]) continue;
        vis[v] = 1;
        ans++;
        if(ans >= 1e6){
            cout << 1000000 << endl;
            exit(0);
        }
        dfs(v,u);
        vis[v] = 0;
    }
}
void solve() {
    int n,m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    vis[1] = 1;
    dfs(1,-1);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}