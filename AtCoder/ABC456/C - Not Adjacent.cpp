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
    vector<int> dp(n+1);
    dp[1] = 1;
    int ans = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (s[i] == s[i-1] ? 1 : (dp[i-1] + 1) % mod);
        ans = (ans + dp[i]) % mod;
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