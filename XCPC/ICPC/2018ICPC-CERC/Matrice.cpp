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
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<char>>a(n+2,vector<char>(m+2));
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            a[i][j] = s[j];
        }
    }
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    rep(i,1,n) rep(j,1,m) dp[i][j] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
           if(a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1]){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                ans += dp[i][j] - 1;
           }
        }
    }
    rep(i,1,n) rep(j,1,m) dp[i][j] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
           if(a[i][j] == a[i-1][j] && a[i][j] == a[i][j+1]){
                dp[i][j] = min(dp[i-1][j], dp[i][j+1]) + 1;
                ans += dp[i][j] - 1;
           }
        }
    }

    rep(i,1,n) rep(j,1,m) dp[i][j] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++){
           if(a[i][j] == a[i+1][j] && a[i][j] == a[i][j-1]){
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                ans += dp[i][j] - 1;
           }
        }
    }
    rep(i,1,n) rep(j,1,m) dp[i][j] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
           if(a[i][j] == a[i+1][j] && a[i][j] == a[i][j+1]){
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + 1;
                ans += dp[i][j] - 1;
           }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}