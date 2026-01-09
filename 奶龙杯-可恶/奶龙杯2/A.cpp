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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve(){
    int n,m; cin >> n >> m;
    vector<int> s(n+1);
    rep(i,1,n) cin >> s[i];
    if(m >= n){
        int ans = 1;
        for(int i = 1; i <= n; i++){
            if(s[i] == 0){
                ans = ans * m % mod;
            }
        }
        cout << ans << endl;
        return;
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= min(m+1,i); j++){
            if(s[i] == 1 && j){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = (dp[i-1][j] * j % mod + (j ? dp[i-1][j-1] * (m + 1 - j) % mod : 0)) % mod;
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= m + 1; j++){
        ans = (ans + dp[n][j]) % mod;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}