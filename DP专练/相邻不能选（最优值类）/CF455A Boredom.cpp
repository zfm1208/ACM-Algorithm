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
    int mx = 0;
    vector<int> cnt(N); 
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    vector<int> dp(mx+1);
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2; i <= mx; i++){
        dp[i] = max(dp[i-1], dp[i-2] + i * cnt[i]);
    }
    cout << dp[mx] << endl;
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