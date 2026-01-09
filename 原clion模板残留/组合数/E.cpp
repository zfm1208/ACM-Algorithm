#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int fact[N]; // 阶乘
int inv_fact[N]; // 逆元阶乘
int ksm(int a,int b,int mod){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void init(int mod){
    fact[0] = inv_fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = inv_fact[i - 1] * ksm(i,mod - 2,mod) % mod;
    }
}
int comp(int a,int b,int m){
    if(a < b) return 0;
    return fact[a] * inv_fact[b] % m * inv_fact[a - b] % m;
}
void solve() {
    int n,m,p; cin >> n >> m >> p;
    init(p);
    cout << comp(n + m, m, p) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
