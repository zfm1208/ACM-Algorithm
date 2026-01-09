//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int fact[N]; // 阶乘数组
int inv_fact[N]; // 阶乘的逆元数组
int mod = 1e9+7;
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
int comb(int n, int m){ //
    return fact[n] * inv_fact[m] % mod * inv_fact[n - m] % mod;
}
void solve() {
    init();
    int k,n; cin >> n >> k;
    cout << (comb(2*n,n) - comb(2*n,n-1) + mod) % mod * ksm(k,n) % mod<< endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}