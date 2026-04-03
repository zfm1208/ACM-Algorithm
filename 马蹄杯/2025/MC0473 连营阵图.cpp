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
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<int> dp(n);
    dp[0] = (s[0][0] == s[1][0] ? 1 : 2);
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1];
        if(s[1][i] == s[0][i]){
            if(s[1][i-1] != s[1][i] && s[0][i-1] != s[1][i]){
                dp[i]++;
            }
        }else{
            if(s[0][i] != s[0][i-1]){
                dp[i]++;
            }
            if(s[1][i] != s[1][i-1]){
                dp[i]++;
            }           
        }
    }
    cout << dp[n-1] << endl;
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