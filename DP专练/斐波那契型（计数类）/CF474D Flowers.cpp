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
    int t,k; cin >> t >> k;
    // dp[i]: 吃i朵花需要的方案数
    vector<int> dp(N),pre(N);
    dp[0] = 1;
    for(int i = 1; i < N; i++){
        if(i < k) dp[i] = dp[i-1] % mod;
        else dp[i] = (dp[i-1] + dp[i-k]) % mod;
        pre[i] = (pre[i-1] + dp[i]) % mod;
    }
    while(t--){
        int a,b; cin >> a >> b;
        cout << (pre[b] - pre[a-1] + mod) % mod << endl;;
    }
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