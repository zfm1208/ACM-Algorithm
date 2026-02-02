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
void solve1(){
    int n; cin >> n;
    int sum = 0;
    vector<int> dp(n+1);
    for(int i = 1; i < n; i++){
        dp[i] = dp[n%i] + 1;
        sum += dp[i];
    }
    cout << fixed << setprecision(10) << (long double)(sum * 1.0 / (long double)(n-1)) << endl;
}
void solve(){
    int n; cin >> n;
    vector<int> ans(n+1);
    // map<int,int> mp; // *sm超时的玩意
    vector<int> mp(n+1,inf);
    auto get = [&](auto& self, int i, int n) -> int {
        if(i <= 1) return 1;
        if(mp[i] != inf) return mp[i];
        return mp[i] = self(self, n%i, n) + 1;
    };
    int sum = 0;
    for(int i = 1; i < n; i++){
        ans[i] = get(get,i,n);
        sum += ans[i];
    }
    cout << fixed << setprecision(10) << (long double)(sum * 1.0 / (long double)(n-1)) << endl;
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