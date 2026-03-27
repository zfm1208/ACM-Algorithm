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
    string s; cin >> s;
    int n = s.size();
    int ans = inf;
    for(int d = 0; d < 26; d++)
    {
        vector<vector<int>> dp(n+1,vector<int>(26));
        for(int i = 0; i < 26; i++){
            s.front() - 'a' == i ? dp[0][i] = 0 : dp[0][i] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 26; j++){
                int cost = (s[i] - 'a' == j ? 0 : 1);
                dp[i][j] = min(dp[i-1][(j - d + 26) % 26], dp[i-1][(j + d) % 26]) + cost;
            }
        }
        for(int i = 0; i < 26; i++){
            ans = min(ans, dp[n-1][i]);
        }
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