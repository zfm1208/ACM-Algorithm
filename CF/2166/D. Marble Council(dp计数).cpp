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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 5);
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int mx = 0;
    for(auto [x, y] : mp){
        mx = max(mx, y);
    }
    vector<int> dp(n + 5);
    dp[0] = 1;
    for(auto [_, y] : mp){
        for(int i = n; i >= y; i--){
            dp[i] = (dp[i] + dp[i - y] * y % mod) % mod;
        }
    }
    int ans = 0;
    for(int i = mx; i <= n; i++){
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}