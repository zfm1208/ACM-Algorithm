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

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<pair<int, double>>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v;
        double w;
        cin >> u >> v >> w;
        w /= 100.0;
        adj[u].push_back({v,w});
    }

    // 从节点 u 出发，采取最优策略，最终能够到达终点 n 的最大概率
    vector<double> dp(n+1, -1);
    auto dfs = [&] (auto&self, int u) -> double {
        if(u == n) return 1;
        if(adj[u].size() == 0) return 0;
        if(dp[u] != -1) return dp[u];
        vector<pair<double,double> > cun;
        for(auto[v,w] : adj[u]){
            dp[v] = self(self, v);
            cun.push_back({w, dp[v]});
        }
        sort(cun.begin(), cun.end(), [](auto x, auto y){
            return x.se > y.se;
        });
        double faild = 1.0;
        double sum = 0.0;
        for(auto [x,y]: cun){
            sum += y * x * faild;
            faild *= (1.0 - x);
        }
        
        return dp[u] = sum;
    };
    dfs(dfs, 1); 
    cout << fixed << setprecision(8) << dp[1] << endl;
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