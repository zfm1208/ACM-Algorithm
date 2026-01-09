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
void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i++){
        w[i] = w[i - 1] + a[(i + 1) / 2];
    }
    vector<int> dp(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int len = 0; len <= n; len++){
            for(int j = 0; j * (i + 1) <= len; j++){
                dp[len] = max(dp[len], dp[len - j * (i + 1)] + j * w[i]);
            }
            ans = max(ans, dp[len]);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}