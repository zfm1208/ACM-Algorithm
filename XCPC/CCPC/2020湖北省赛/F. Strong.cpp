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
    int n,l,r; cin >> n >> l >> r;
    vector<int> a(n+1),pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++){
        if(l <= a[i] && a[i] <= r){
            dp[i] = dp[i-1] + 1;
        }else{
            for(int j = i; j >= 1; j--){
                int sum = pre[i] - pre[j-1];
                if(l <= sum && sum <= r){
                    dp[i] = max(dp[i], dp[j-1] + 1);
                }else{
                    dp[i] = max(dp[i], dp[j]);
                }
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