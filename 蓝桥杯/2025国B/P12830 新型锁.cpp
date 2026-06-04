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
/*
2025 = 3^4 * 5^2
LCM -> 指数 max
拆成 e = 4 和 e = 2 两个问题
每个问题都是：不能连续两个非最高指数
递推 f(n) = f(n-1) + e * f(n-2)
答案 = f4(2025) * f2(2025)

*/
// Each value is in [0, e], and max of every adjacent pair must be e.
// f[0] = 1, f[1] = e + 1, f[n] = f[n - 1] + e * f[n - 2]
int calc(int e, int n){
    if(n == 0) return 1;
    if(n == 1) return e + 1;
    int f0 = 1, f1 = e + 1;
    for(int i = 2; i <= n; i++){
        int f2 = (f1 + e * f0) % mod;
        f0 = f1;
        f1 = f2;
    }
    return f1;
}

void solve(){
    // 2025 = 3^4 * 5^2. Count the two prime exponents independently.
    int n = 2025;
    int ans = calc(4, n) * calc(2, n) % mod;
    cout << ans << endl;
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
