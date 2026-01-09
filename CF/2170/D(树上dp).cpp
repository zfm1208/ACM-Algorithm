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
    vector<int> p(n+1),dep(n+1),dp(n+1);
    vector<int> rom[n+1];
    rom[0].pb(1);
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        dep[i] = dep[p[i]]+1;
        rom[dep[i]].pb(i);
    }
    dp[1] = 1;
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(rom[i].empty()) break;
        int pre = 0;
        for(auto v: rom[i-1]){
            pre = (pre + dp[v]) % mod;
        }
        for(auto u: rom[i]){
            if(i == 1) dp[u] = dp[1];
            else dp[u] = (pre - dp[p[u]] + mod) % mod;
            ans = (ans + dp[u]) % mod;
        }
    }
    cout << ans << endl;

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