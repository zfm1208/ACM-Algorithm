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
// 法1 floyd 判环
void solve1(){
    // n 范围只有100, 可以n^3暴力
    int n,m; cin >> n >> m;
    // 用Floyd 判断有没有环
    // g[u][v] = 1 表示: u > v 
    vector<vector<int>> g(n+1,vector<int>(n+1));    
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        g[u][v] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(g[i][k] && g[k][j]){
                    g[i][j] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(g[i][i]){
            rep(i,1,n) cout << 0;
            cout << endl; return;
        }
    }

    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        int small = 0,big = 0;
        for(int j = 1; j <= n; j++){
            if(g[i][j]) small++;
            if(g[j][i]) big++;
        }
        if(small <= n/2 && big <= n/2){
            ans[i] = 1;
        }
    }

    rep(i,1,n) cout << ans[i];
    cout << endl;
}
// 法2 bfs 拓扑排序->判有向图是否有环
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> re_adj(n+1);
    vector<int> du(n+1); // 入度
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        // u -> v (u > v)
        du[v]++;

        re_adj[v].pb(u);
    }
    
    auto has_cycle = [&] (int n) -> bool {
        int cnt = 0;
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(du[i] == 0) q.push(i);
        }
        while(q.size()){
            int u = q.front();
            q.pop();
            cnt++;
            for(int v : adj[u]){
                du[v]--;
                if(du[v] == 0) q.push(v);
            }
        }
        return cnt < n;
    };

    if(has_cycle(n)){
        rep(i,1,n) cout << 0;
        cout << endl; return;
    }

    vector<int> ans(n+1);

    auto bfs = [&] (int st, const vector<vector<int>>& g) -> int {
        queue<int> q;
        q.push(st);
        vector<int> vis(n+1,0);
        vis[st] = 1;
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : g[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    cnt++;
                    q.push(v);
                }
            }
        }
        return cnt;
    };


    // 对每个点跑bfs 计算比它大的和比它小的
    for(int i = 1; i <= n; i++){
        int small = bfs(i,adj);
        int big = bfs(i,re_adj);
        if(small <= n/2 && big <= n/2){
            ans[i] = 1;
        }
    }
    rep(i,1,n) cout << ans[i];
    cout << endl;

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