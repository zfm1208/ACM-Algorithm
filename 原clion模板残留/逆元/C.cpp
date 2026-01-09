#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
// 欧拉函数 phi(m)
int phi(int m) {
    int res = m;
    for(int p = 2; p * p <= m; p++){
        if(m % p == 0){
            while(m % p == 0)m /= p;
            res -= res / p;
        }
    }
    if(m > 1)res -= res / m;
    return res;
}
int ksm(int a, int b, int mod){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int eular(int a, int m){
    int p = phi(m);
    return ksm(a,p -1 ,m);
}
void solve() {
    //求关于x的同余方程  a * x ≡ 1 (modx) 的最小正整数解
    int a,m; cin >> a >> m;
    int inv = eular(a,m);
    cout << inv;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
