#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 1e6 + 10;
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
//int fact[N];
//int inv[N];
//void init(){
//    inv[0] = fact[0] = 1;
//    for(int i = 1;i < N;i++){
//        fact[i] = fact[i - 1] * i % mod;
//        inv[i] = ksm(fact[i],mod - 2) % mod;
//    }
//}
//int C(int n,int m){
//    if(n < m) return 0;
//    return fact[n] * inv[m] % mod * inv[n - m] % mod;
//}
void ff(){
//    init();
    int n;cin >> n;
    if(n < 3){
        cout << 0 << endl;
        return;
    }
    int t = n-3;
    int ans = 6 * ksm(26,t) % mod;
    int tp  = (t+1) * t % mod * (t-1)  % mod / 6; // 3zu
    int tp1 = (t+1) * t  * 3 / 2 % mod ; // 2zu
    int tp2 = t+1; // 1zu
    int sum = (tp+tp1) % mod + tp2;
    sum %= mod;
    ans = ans * sum % mod;
    cout << ans ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--){
        ff();
    }
    return 0;
}