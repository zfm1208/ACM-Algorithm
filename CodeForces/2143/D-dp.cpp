// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r)for(int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
double pi = acos(-1);
const int N = 2e5 + 10, mod = 1e9+7, inf = 1e18 + 5;
void solve(){ 
    int n; cin >> n; 
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % mod;
                if(a[i] >= j){
                    dp[i][a[i]][k] = (dp[i][a[i]][k] + dp[i-1][j][k]) % mod;
                }else if(a[i] >= k){
                    dp[i][j][a[i]] = (dp[i][j][a[i]] + dp[i - 1][j][k] ) % mod;
                }else{

                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= n; j++){
        for(int k = 0; k <= j; k++){
            ans = (ans + dp[n][j][k]) % mod;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}