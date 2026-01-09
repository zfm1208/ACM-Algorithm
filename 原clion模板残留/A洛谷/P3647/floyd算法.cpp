#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int n,m;
vector<vector<int>> dp(110,vector<int> (110,1e18));
void solve() {
    cin >> n >> m;
    int u,v,w;
    while(m--){
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v],w);
        dp[v][u] = min(dp[v][u],w);
    }
    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
                dp[j][i] = min(dp[j][i],dp[i][k] + dp[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
