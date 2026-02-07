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
/*
    s[l,r] 中至少有 0，1
    [l,r-1]中存在i使得 s[i] != s[i+1]
*/
void solve() {
    int n,m; cin >> n >> m;
    vector<int> L(n+1);
    for(int i = 1; i <= m; i++){
        int l,r; cin >> l >> r;
        r--;
        L[r] = max(L[r],l);
    }
    vector<int> lim(n+1);
    int cur = 0;
    for(int i = 1; i <= n; i++){
        cur = max(cur,L[i-1]);
        lim[i] = cur;
    }
    vector<int> dp(n+1),pre(n+1);
    pre[0] = dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(lim[i] < i){
            if(lim[i] == 0){
                dp[i] = pre[i - 1] % mod;
            }else{
                dp[i] = (pre[i - 1] - pre[lim[i] - 1] + mod) % mod;
            }            
        }else{
            dp[i] = 0;
        }
        pre[i] = (pre[i - 1] + dp[i]) % mod;
    }
    dp[n] = dp[n] * 2 % mod;
    cout << dp[n] << endl;
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