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
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> dp(n+1); 
    // 前i个消灭的最小次数
    dp[0] = 0;
    dp[1] = a[1];
    for(int i = 2; i <= n; i++){
        // case1: 直接击毙（-1是因为前i-1个结束后，第i个要摔下去，血量-1）
        dp[i] = dp[i-1] + a[i] - 1;
        // case2: 摔死
        dp[i] = min(dp[i],dp[i-2] + a[i-1] + max(a[i]-i+1,0LL));
    }
    cout << dp[n] << endl;
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