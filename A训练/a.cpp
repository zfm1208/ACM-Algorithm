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
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    sort(a.begin()+1,a.end(),greater<int>());
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= a[i] && dp[i-1][j - a[i]] == 1){
                dp[i][j] = 1;
            }
        }
    }
    if(dp[n][m] == 0){
        cout << "No Solution";
        return;
    }
    vector<int> ans;
    for(int i = n; i >= 1; i--){
        if(m >= a[i] && dp[i-1][m-a[i]] == 1){
            m -= a[i];
            ans.pb(a[i]);
        }
    }
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << (i == (int)ans.size()-1 ? "" : " ");
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