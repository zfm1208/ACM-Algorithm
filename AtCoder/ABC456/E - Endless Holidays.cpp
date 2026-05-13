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
// 在状态转移图上，从一个合法的起点出发，能否找到一个环？
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int w; cin >> w;
    vector<string> s(n+1);
    rep(i,1,n) cin >> s[i];
    vector<vector<int>> vis(n + 1, vector<int>(w));
    auto dfs = [&] (auto& self, int u, int d) -> bool {
        // 碰到了还在递归栈里的节点，说明找到了环！
        if(vis[u][d] == 1) return true; 
        // 碰到了已经确认无环的节点（死胡同），直接剪枝
        if(vis[u][d] == 2) return false; 
        vis[u][d] = 1; // 标记为正在访问
        int nd = (d + 1) % w;

        if(s[u][nd] == 'o') {
            if(self(self, u, nd)) return true;
        }

        for(int v: adj[u]){
            if(s[v][nd] == 'o'){
                if(self(self, v, nd)) return true;
            }
        }
        vis[u][d] = 2;// 后续没有环，标记为死胡同
        return false;
    };
    // 枚举所有合法起点：第 1 天（下标 0）必须是节假日
    for(int i = 1; i <= n; i++){
        if(s[i][0] == 'o' && vis[i][0] == 0){
            if(dfs(dfs, i, 0)){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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