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

void solve(){
    int n,m; cin >> n >> m;
    if(m == 1){
        cout << 0 << endl;
        return;
    }
    vector<array<int,3>> dp(n+1);
    dp[1][0] = m * (m - 1 + mod) % mod;
    dp[1][1] = m * 3 % mod * (m - 1 + mod) % mod * (m - 2 + mod) % mod;
    dp[1][2] = m * (m - 1 + mod) % mod * (m - 2 + mod) % mod * (m - 3 + mod) % mod;
    for(int i = 2; i <= n; i++){
        dp[i][0] = ((dp[i-1][0] * (m - 1 + mod) % mod + 
                    dp[i-1][1] * (m - 2 + mod) % mod) % mod + 
                    dp[i-1][2] * (m - 3 + mod) % mod) % mod;
        dp[i][1] = ((dp[i-1][0] * 3 % mod * (m - 2 + mod) % mod * (m - 1 + mod) % mod + 
                     dp[i-1][1] * ((m - 2 + mod) * (m - 3 + mod) % mod * 2 % mod + (m - 2 + mod) * (m - 2 + mod) % mod) % mod) % mod + 
                     dp[i-1][2] * 3 % mod * (m - 3 + mod) % mod * (m - 3 + mod) % mod) % mod;
        dp[i][2] = ((dp[i-1][0] * (m - 1 + mod) % mod * (m - 2 + mod) % mod * (m - 3 + mod) % mod + 
                     dp[i-1][1] * (m - 2 + mod) % mod * (m - 3 + mod) % mod * (m - 3 + mod) % mod) % mod + 
                     dp[i-1][2] * (((m - 2 + mod) * (m - 2 + mod) % mod * (m - 2 + mod) % mod -  (m - 3 + mod) % mod * (3 * m % mod - 8 + mod) % mod) % mod + mod) % mod) % mod;
    }
    int ans = ((dp[n][0] * (m - 1 + mod) % mod + dp[n][1] * (m - 2 + mod) % mod) % mod + dp[n][2] * (m - 3 + mod) % mod) % mod;
    cout << ans << endl;
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