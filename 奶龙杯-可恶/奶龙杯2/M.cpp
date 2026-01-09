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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
// dp[i][0]: 收集i个数，操作者的期望罚金
// dp[i][1]: 收集i个数，等待者的期望罚金
int dp[N][2];
int inv(int x){return fpow(x,mod-2);}
void solve(){
    int n; cin >> n;
    dp[n][0] = 0;
    dp[n][1] = 0;
    for(int i = n-1; i >= 0; i--){
        int p = i * inv(n) % mod; // 重复数概率
        int q = (n-i) * inv(n) % mod; // 新数概率
        int fm = inv((1 - p * p % mod + mod) % mod);
        int fz = (p + q * (p * dp[i+1][0] % mod + dp[i+1][1]) % mod) % mod;

        dp[i][0] = fz * fm % mod;
        dp[i][1] = (p * dp[i][0] % mod + q * dp[i+1][0] % mod) % mod;
    }
    cout << dp[0][0] << " " << dp[0][1] << endl;
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