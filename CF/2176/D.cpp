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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    记忆化搜素
*/
void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> g(n+1); 
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        g[u].pb(v);
    }
    int ans = 0;
    // mp缓存前一个点的值和当前点 [q2,u]
    map<pii,int> mp;
    auto dfs = [&] (auto &self,int q1,int q2,int u,int fa) -> int {
        if(q1 != -1 && q2 != -1 && q1 + q2 != a[u]){
            return 0;
        }
        if(q2 != -1 && mp.count({q2,u})){
            return mp[{q2,u}];
        }
        // 若路径已有至少2个数,路径合法,贡献+1
        int res = (q2 != -1);
        for(auto v: g[u]){
            if(v == fa) continue;
            res = (res + self(self,q2,a[u],v,u)) % mod;
        }
        if(q2 != -1) mp[{q2,u}] = res;
        if(q1 == -1 && q2 == -1){
            ans = (ans + res) % mod;
        }
        return res;
    };

    for(int i = 1; i <= n; i++){
        dfs(dfs,-1,-1,i,-1);
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