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
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    // dp[i][op]； 前i个位置，并且以字符op结尾的最大合法方式数
    vector<vector<int>> dp(n+1,vector<int>(3));
    dp[1][s[1] - 'a'] = 1;
    for(int i = 2; i <= n; i++){
        int op = s[i] - 'a';
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];
        dp[i][op] = (dp[i][op] + dp[i-1][(op + 1) % 3] + dp[i-1][(op + 2) % 3] + 1) % mod;
    }
    int ans = 0;
    for(int i = 0; i <= 2; i++){
        ans = (ans + dp[n][i]) % mod;
    }
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