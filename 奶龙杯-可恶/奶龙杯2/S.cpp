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

void solve(){
    int n,m; cin >> n >> m;
    vector<int> p(n+1,n);
    vector<pii> qz[n+1];
    while(m--){
        int u,v,w; cin >> u >> v >> w;
        qz[w].pb({u,v});
        p[u] = min(p[u],w);
        p[v] = min(p[v],w);
    }
    vector<int> up[n+1];
    for(int i = 1; i <= n; i++) up[p[i]].pb(i);
    int ans = 1;
    int cnt = 0; // 有多少数可以放i
    for(int i = n; i >= 1; i--){
        cnt += up[i].size();
        if(qz[i].size() == 0){
            ans = ans * cnt % mod;
            cnt--;
        }else{
            auto [u1,u2] = qz[i][0];
            int cn = 0;
            auto check =[&](int u) -> bool {
                if(p[u] != i) return false;
                for(auto [x,y] : qz[i]){
                    if(x != u && y != u) return false;
                }
                return true;
            };
            if(check(u1)) cn++;
            if(check(u2)) cn++;
            ans = ans * cn % mod;
            cnt--;            
        }
        if(ans == 0 || cnt < 0){ 
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
    //cin >> T;
    while(T--)
        solve();
    return 0;
}