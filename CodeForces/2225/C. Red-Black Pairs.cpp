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
    string s1,s2; 
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    vector<int> dp(n+1,inf);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(i >= 2){
            int cost = (s1[i-1] != s1[i] ? 1 : 0) + (s2[i-1] != s2[i] ? 1 : 0);
            dp[i] = min(dp[i], dp[i-2] + cost);            
        }
        int cost1 = (s1[i] != s2[i] ? 1 : 0);
        dp[i] = min(dp[i], dp[i-1] + cost1);
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