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
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(2));
    dp[0][0] = 1; // 第i个人诚实
    dp[0][1] = 0; // 第i个人说谎
    for(int i = 1;i <= n; i++){
        // 如果第i个人诚实
        if(a[i] == a[i-1]){
            dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
        }
        if(i >= 2 && a[i] == a[i-2] + 1){
            dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
        }
        // 如果第i个人说谎
        dp[i][1] = dp[i-1][0] % mod;
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl;
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