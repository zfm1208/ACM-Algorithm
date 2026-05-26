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
// f(x,rem) = (x - rem) / m + 1 
int get(int x, int rem) {
    if (x < 0) return 0;
    if (rem == 0) return x / 3;
    if (rem == 1) return (x + 2) / 3;
    if (rem == 2) return (x + 1) / 3;
    return 0;
}
void solve(){
    int n,l,r; cin >> n >> l >> r;
    // dp[i][j] 前 i 个数和模 3 余 j
    vector<vector<int>> dp(n+1, vector<int>(3));
    // 不要忘记初始化
    dp[0][0] = 1;
    int cnt[3];
    cnt[0] = get(r, 0) - get(l - 1, 0);
    cnt[1] = get(r, 1) - get(l - 1, 1);
    cnt[2] = get(r, 2) - get(l - 1, 2);
    for(int i = 1; i <= n; i++){
        dp[i][0] = (dp[i - 1][0] * cnt[0] % mod + dp[i - 1][1] * cnt[2] % mod + dp[i - 1][2] * cnt[1] % mod) % mod;
        dp[i][1] = (dp[i - 1][0] * cnt[1] % mod + dp[i - 1][1] * cnt[0] % mod + dp[i - 1][2] * cnt[2] % mod) % mod;
        dp[i][2] = (dp[i - 1][0] * cnt[2] % mod + dp[i - 1][1] * cnt[1] % mod + dp[i - 1][2] * cnt[0] % mod) % mod;
    }
    cout << dp[n][0] << endl;
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