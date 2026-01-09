#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 5e6 + 5;
int fact[N]; // 阶乘数组
int inv_fact[N]; // 阶乘的逆元数组
int mod;
int ksm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void init(){
    fact[0] = inv_fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = fact[i - 1] * i % mod;
        inv_fact[i] = inv_fact[i - 1] * ksm(i, mod - 2) % mod;
    }
}
// 计算组合数C(n, m) % MOD
int C(int n, int m){
    return fact[n] * inv_fact[m] % mod * inv_fact[n - m] % mod;
}
void solve() {
    int res = 0;
    init();
    int n,m; cin >> n >> m >> mod;
    res ^= C(n+m,m);
    cout << res << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
