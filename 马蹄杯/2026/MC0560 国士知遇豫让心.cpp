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
/*
    考虑树上dp,自底向上进行dp
    把左括号当作1，右括号当作-1、
    考虑当前以u为根的子树中
    从根节点到u(不包含u)的简单路径上，前缀和为x 的方案数
    记作dp[u][x]

    可知叶子节点 dp[u][1] = 1;
    我们要求 dp[1][0]

    状态转移,考虑当前节点u 作为 ( 和 "")"的贡献
    两种互斥相加,对于每一种对待子节点v当然是累乘


    
*/
void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // dp[u][i] : 当前以u节点为根时，从根节点到u(不包括u)的路径上不匹配的括号个数

    vector<vector<int>> dp(n+1,vector<int>(n+1));
    auto dfs = [&](auto& self, int u, int fa) -> void {
        if(adj[u].size() == 1 && fa != 0){
            dp[u][1] = 1;
            return;
        }
        for(int v: adj[u]){
            if(v == fa) continue;
            self(self, v, u);
        }
        for(int i = 0; i < n; i++){
            int a = 1, b = 1;
            for(int v: adj[u]){
                if(v == fa) continue;
                a = a * dp[v][i+1] % mod;
                if(i > 0) 
                b = b * dp[v][i-1] % mod;
            }
            if(i == 0){
                dp[u][i] = a;
            }else{
                dp[u][i] = (a + b) % mod;
            }
        }
    };
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    dfs(dfs, 1, 0);
    cout << dp[1][0] << endl;
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