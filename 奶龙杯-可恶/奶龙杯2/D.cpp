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
const int N = 5e3+10, mod = 998244353, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int n; 
vector<int> e[N];
int dp[N][N][2]; // dp[u][i][0/1] : 结点u在交换了多少次，有没有和爸爸互换
int tp[N][N][2]; // 临时数组
int siz[N];
void dfs(int u, int fa){
    siz[u] = 1;
    dp[u][0][0] = 1;
    if(u!=1)dp[u][1][1] = 1;
    for(auto v: e[u]){
        if(v == fa) continue;
        dfs(v,u);
        int sum0 = 0,sum1 = 0;
        for(int i = 0; i <= siz[v]; i++){
            sum0 = (sum0 + dp[v][i][0]) % mod;
            sum1 = (sum1 + dp[v][i][1]) % mod;
        }
        for(int i = 0; i <= siz[u] + 1; i++){ // 必须clear
            tp[u][i][0] = tp[u][i][1] = 0;
        }
        for(int i = 0; i <= siz[u]; i++){
            // u 和 v 不交换
            tp[u][i][0] = (tp[u][i][0] + dp[u][i][0] * sum0 % mod) % mod;
            tp[u][i][1] = (tp[u][i][1] + dp[u][i][1] * sum0 % mod) % mod;
            // u 和 v 交换
            tp[u][i+1][0] = (tp[u][i+1][0] + dp[u][i][0] * sum1 % mod * (i+1) % mod) % mod;
            tp[u][i+1][1] = (tp[u][i+1][1] + dp[u][i][1] * sum1 % mod * (i+1) % mod) % mod;
        }
        for(int i = 0; i <= siz[u] + 1; i++){
            dp[u][i][0] = tp[u][i][0];
            dp[u][i][1] = tp[u][i][1];            
        }
        siz[u] += siz[v];
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1,0);
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = (ans + dp[1][i][0]) % mod;
    }
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