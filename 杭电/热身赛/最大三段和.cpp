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
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> dp(n+1,-inf),pre(n+1,-inf);
    for(int i = 1; i <= n; i++){
        if(i==1 || dp[i-1] + a[i] < a[i]){
            dp[i] = a[i];
        }else{
            dp[i] = dp[i-1] + a[i];
        }
        if(i == 1) pre[i] = dp[i];
        else{
            pre[i] = max(pre[i-1], dp[i]);
        }
    }
    vector<int> dp1(n+2,-inf),suf(n+2,-inf);
    for(int i = n; i >= 1; i--){
        if(i == n || dp1[i+1] + a[i] < a[i]){
            dp1[i] = a[i];
        }else{
            dp1[i] = dp1[i+1] + a[i];
        }
        if(i == n){
            suf[i] = dp1[i];
        }else{
            suf[i] = max(suf[i+1],dp1[i]);
        }
    }
    int ans = -inf;
    for(int i = 1; i <= n; i++){
        if(i-2 >= 1 && i+2 <= n)
        ans = max(ans, a[i] + pre[i-2] + suf[i+2]);
    }
    cout << ans << endl;
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