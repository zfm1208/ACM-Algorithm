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
// https://ac.nowcoder.com/acm/contest/130418/G
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        for(int len = 3; len <= 9; len += 3){
            if(i < len) continue;
            map<int,int> mp;
            for(int j = 0; j < len; j++){
                mp[a[i-j]]++;
            }
            if(mp[1] == mp[2] && mp[2] == mp[3] && mp[1] == len / 3){
                dp[i] = max(dp[i], dp[i-len] + len);
            }
        }
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