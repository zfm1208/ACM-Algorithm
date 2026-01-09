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
const int N = 1e5, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int n,m;
vector<pii> g[N];
int dist[N];
void BF(bool &ok,int tp){
    for(int i = 1; i <= n; i++) dist[i] = inf;
    dist[1] = 0;
    // n-1次BF + 1次测负环
    for(int i = 1; i <= n; i++){
        for(int u = 1; u <= n; u++){
            // 不要加&[v,w] !!!,不能修改原值
            for(auto [v,w] : g[u]){
                w*=tp;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    if(i == n){
                        ok = 1;
                        return;
                    }
                }
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        char c; cin >> c;
        g[u].pb({v,(c == '(' ? 1 : -1)});
    }
    bool cz = 0,cf = 0; 
    BF(cz, 1);
    BF(cf, -1);
    // cout << cz << " " << cf << endl;
    cout << (cz ^ cf ? "No" : "Yes") << endl;  
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