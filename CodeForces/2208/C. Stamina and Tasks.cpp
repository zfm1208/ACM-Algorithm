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
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    // int S = 100;
    // vector<vector<double>> dp(n + 1, vector<double>(105, -1e9));    
    // dp[0][100] = 0.0;
    // for(int i = 1; i <= n; i++){
    //     for (int j = 0; j <= 100; j++) {
    //         if (dp[i - 1][j] < -1e8) continue;
    //         dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    //         if(j >= a[i].se){
    //             int ts = j - a[i].se;
    //             double cost = (j / 100.0) * a[i].fi;
    //             dp[i][ts] = max(dp[i][ts], dp[i - 1][j] + cost);
    //         }
    //     }
    // }
    // double ans = 0;
    // for(int i = 0; i <= 100; i++){
    //     ans = max(ans,dp[n][i]);
    // }
    // cout << fixed << setprecision(10) << ans << endl;
    long double S = 1;
    vector<long double> dp(n+2);
    dp[n] = max(dp[n+1],(long double)a[n].fi * S);
    for(int i = n-1; i >= 1; i--){
        dp[i] = max(dp[i+1], a[i].fi * S + dp[i+1] * (1-a[i].se / 100.0));
    }
    cout << fixed << setprecision(10) << dp[1] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}