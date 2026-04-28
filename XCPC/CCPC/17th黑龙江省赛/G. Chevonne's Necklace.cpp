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
// https://codeforces.com/gym/103688/problem/G
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0) continue;
        for(int j = n; j >= a[i]; j--){
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }
    for(int i = n; i >= 0; i--){
        if(dp[i]){
            cout << i << " " << dp[i] << endl;
            return;
        }
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