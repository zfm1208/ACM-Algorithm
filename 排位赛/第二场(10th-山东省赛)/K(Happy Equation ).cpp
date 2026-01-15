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
const int N = 1e6, inf = 1e18 + 5;
int qpow(int a,int b,int mod){
    int res = 1;
    a %= mod;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void dabioa(){
    for(int p = 1; p <= 10; p++){
        int mod = 1LL << p; 
        cout << "========== p = " << p << ", mod = " << mod << " ==========" << endl;
        for(int a = 1; a <= 20; a++){
            int cnt = 0;
            for(int x = 1; x <= mod; x++) {
                // a^x % p = x^a % p
                if(qpow(a, x, mod) == qpow(x, a, mod)){
                    cnt++;
                }
            }
            cout << "a = " << a << " , ans = " << cnt << endl;
        }
        cout << endl;
    }
}
void solve(){
    int a,p; cin >> a >> p;
    if(a&1){cout << 1 << endl; return;}
    // a^x % p = x^a % p
    int ans = 0;
    // * 分界线p
    /*
        a是偶数,a >= 2
        x >= p 时; 左边 a^x >= 2^p
        由于a包含因子2，所以a^x 一定包含因子2^x
        如果 x >= p ,那么a^x包含至少p个因子2
        这意味着 x >= p 时, (a^x) % (2^p) == 0
    */    
    // x < p 暴力求解即可
    for(int x = 1; x < p; x++){
        ans += (qpow(a,x,1<<p) == qpow(x,a,1<<p));
    }
    // x >= p
    /*
        要是 x^a % 2^p == 0，那么x^a中,因子2的个数至少有p个
        设x的因子中有k个2, 那么 x^a 就有a*k个因子2
        ==> (a*k >= p)
        k >= ceil(p/a)
    */
    int k = (p+a-1)/a;
    // (2^p) / (2^k) 
    // [1-p-1]里面2*k倍数的个数
    ans += (1 << (p-k)) - (p-1) / (1 << k);
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
/*
========== p = 1, mod = 2 ==========
a = 1 , ans = 1
a = 2 , ans = 1
a = 3 , ans = 1
a = 4 , ans = 1
a = 5 , ans = 1
a = 6 , ans = 1
a = 7 , ans = 1
a = 8 , ans = 1
a = 9 , ans = 1
a = 10 , ans = 1
a = 11 , ans = 1
a = 12 , ans = 1
a = 13 , ans = 1
a = 14 , ans = 1
a = 15 , ans = 1
a = 16 , ans = 1
a = 17 , ans = 1
a = 18 , ans = 1
a = 19 , ans = 1
a = 20 , ans = 1

========== p = 2, mod = 4 ==========
a = 1 , ans = 1
a = 2 , ans = 2
a = 3 , ans = 1
a = 4 , ans = 2
a = 5 , ans = 1
a = 6 , ans = 2
a = 7 , ans = 1
a = 8 , ans = 2
a = 9 , ans = 1
a = 10 , ans = 2
a = 11 , ans = 1
a = 12 , ans = 2
a = 13 , ans = 1
a = 14 , ans = 2
a = 15 , ans = 1
a = 16 , ans = 2
a = 17 , ans = 1
a = 18 , ans = 2
a = 19 , ans = 1
a = 20 , ans = 2

========== p = 3, mod = 8 ==========
a = 1 , ans = 1
a = 2 , ans = 3
a = 3 , ans = 1
a = 4 , ans = 4
a = 5 , ans = 1
a = 6 , ans = 3
a = 7 , ans = 1
a = 8 , ans = 4
a = 9 , ans = 1
a = 10 , ans = 3
a = 11 , ans = 1
a = 12 , ans = 4
a = 13 , ans = 1
a = 14 , ans = 3
a = 15 , ans = 1
a = 16 , ans = 4
a = 17 , ans = 1
a = 18 , ans = 3
a = 19 , ans = 1
a = 20 , ans = 4

========== p = 4, mod = 16 ==========
a = 1 , ans = 1
a = 2 , ans = 5
a = 3 , ans = 1
a = 4 , ans = 8
a = 5 , ans = 1
a = 6 , ans = 7
a = 7 , ans = 1
a = 8 , ans = 8
a = 9 , ans = 1
a = 10 , ans = 7
a = 11 , ans = 1
a = 12 , ans = 8
a = 13 , ans = 1
a = 14 , ans = 7
a = 15 , ans = 1
a = 16 , ans = 8
a = 17 , ans = 1
a = 18 , ans = 7
a = 19 , ans = 1
a = 20 , ans = 8

========== p = 5, mod = 32 ==========
a = 1 , ans = 1
a = 2 , ans = 6
a = 3 , ans = 1
a = 4 , ans = 9
a = 5 , ans = 1
a = 6 , ans = 14
a = 7 , ans = 1
a = 8 , ans = 16
a = 9 , ans = 1
a = 10 , ans = 14
a = 11 , ans = 1
a = 12 , ans = 15
a = 13 , ans = 1
a = 14 , ans = 14
a = 15 , ans = 1
a = 16 , ans = 16
a = 17 , ans = 1
a = 18 , ans = 14
a = 19 , ans = 1
a = 20 , ans = 15

========== p = 6, mod = 64 ==========
a = 1 , ans = 1
a = 2 , ans = 10
a = 3 , ans = 1
a = 4 , ans = 17
a = 5 , ans = 1
a = 6 , ans = 30
a = 7 , ans = 1
a = 8 , ans = 32
a = 9 , ans = 1
a = 10 , ans = 30
a = 11 , ans = 1
a = 12 , ans = 31
a = 13 , ans = 1
a = 14 , ans = 30
a = 15 , ans = 1
a = 16 , ans = 32
a = 17 , ans = 1
a = 18 , ans = 30
a = 19 , ans = 1
a = 20 , ans = 31

========== p = 7, mod = 128 ==========
a = 1 , ans = 1
a = 2 , ans = 10
a = 3 , ans = 1
a = 4 , ans = 33
a = 5 , ans = 1
a = 6 , ans = 32
a = 7 , ans = 1
a = 8 , ans = 63
a = 9 , ans = 1
a = 10 , ans = 61
a = 11 , ans = 1
a = 12 , ans = 63
a = 13 , ans = 1
a = 14 , ans = 61
a = 15 , ans = 1
a = 16 , ans = 64
a = 17 , ans = 1
a = 18 , ans = 61
a = 19 , ans = 1
a = 20 , ans = 63

========== p = 8, mod = 256 ==========
a = 1 , ans = 1
a = 2 , ans = 18
a = 3 , ans = 1
a = 4 , ans = 65
a = 5 , ans = 1
a = 6 , ans = 64
a = 7 , ans = 1
a = 8 , ans = 127
a = 9 , ans = 1
a = 10 , ans = 125
a = 11 , ans = 1
a = 12 , ans = 127
a = 13 , ans = 1
a = 14 , ans = 125
a = 15 , ans = 1
a = 16 , ans = 128
a = 17 , ans = 1
a = 18 , ans = 125
a = 19 , ans = 1
a = 20 , ans = 127

========== p = 9, mod = 512 ==========
a = 1 , ans = 1
a = 2 , ans = 18
a = 3 , ans = 1
a = 4 , ans = 66
a = 5 , ans = 1
a = 6 , ans = 127
a = 7 , ans = 1
a = 8 , ans = 128
a = 9 , ans = 1
a = 10 , ans = 252
a = 11 , ans = 1
a = 12 , ans = 254
a = 13 , ans = 1
a = 14 , ans = 252
a = 15 , ans = 1
a = 16 , ans = 255
a = 17 , ans = 1
a = 18 , ans = 252
a = 19 , ans = 1
a = 20 , ans = 254

========== p = 10, mod = 1024 ==========
a = 1 , ans = 1
a = 2 , ans = 34
a = 3 , ans = 1
a = 4 , ans = 130
a = 5 , ans = 1
a = 6 , ans = 255
a = 7 , ans = 1
a = 8 , ans = 256
a = 9 , ans = 1
a = 10 , ans = 508
a = 11 , ans = 1
a = 12 , ans = 510
a = 13 , ans = 1
a = 14 , ans = 508
a = 15 , ans = 1
a = 16 , ans = 511
a = 17 , ans = 1
a = 18 , ans = 508
a = 19 , ans = 1
a = 20 , ans = 510
*/