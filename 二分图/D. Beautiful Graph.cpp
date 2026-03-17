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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
int ksm(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// https://codeforces.com/contest/1093/problem/D
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(n+1);
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i] != 0) continue;
        int cnt1 = 0,cnt2 = 0;
        bool ok = 1;
        auto dfs = [&] (auto& self, int u, int c) -> void {
            vis[u] = c;
            if(c == 1) cnt1++;
            else cnt2++;
            for(int v: adj[u]){
                if(vis[v] == 0){
                    self(self,v,3-c);
                }else if(vis[v] == vis[u]){
                    ok = 0;
                }
            }
        };
        dfs(dfs,i,1);
        if(ok) ans = (ans * (ksm(2,cnt1) % mod + ksm(2,cnt2) % mod) % mod) % mod;
        else{
            cout << 0 << endl;
            return;
        }
    }
    cout << ans << endl;
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