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
const int N = 1e6 + 10, mod = 1e6+3, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    a = 3
    1>  +1 *3
        4 -> 8 -> 16 -> 32
    2> *3
        3 -> 6 -> 12 -> 24
    差值8 = 2^3
    3> *1 +1 *2
        3 -> 6 -> 7 -> 14 -> 28
    差值4 = 2^2

    a -> b
    若有k次*2，t次+1
    b = a * 2^k + temp;
    temp = （第0阶段+t0次）* 2^k + （第1阶段+t1次）* 2^(k-1) +（第2阶段+t2次）* 2^(k-2) +
        ...... +（第k阶段+tk次）* 2^0
    (t0 + t1 + ... + tk = t)

    temp 就是 b-a*(2^k) 的差值
    用2^k,2^(k-1),...,2^0 去凑temp


    最后操作次数ans确定后，我们可以知道在第几阶段+1了多少次，这个是互不影响的。
    多重集排列问题
    t[i] = {1,2,3}
    sum = 1+2+3 = 6;
    ans = 6!  / (1! * 2! * 3!)
*/
int fact[N];
int infact[N];
void init(){
    fact[0] = 1;
    for(int i = 1; i < mod; i++) fact[i] = fact[i-1] * i % mod;
    // inv(i!) * i = inv((i-1)!) 
    infact[mod-1] = fpow(fact[mod-1],mod-2);
    for(int i = mod - 2; i >= 0; i--){
        infact[i] = infact[i+1] * (i+1) % mod;
    }
}
void solve(){
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int k = inf;
    for(int i = 1; i <= n; i++){
        k = min(k,(int)log2(b[i]/a[i]));
    }
    int ans1 = k;
    vector<int> t[100];
    // t[i] 在第i次乘法前 + 了多少次
    for(int i = 1; i <= n; i++){
        int diff = b[i] - a[i] * (1 << k);
        int p = k;
        int ip = 1;
        while(diff){
            int cn = (diff / (1 << p));
            t[ip].pb(cn);
            diff -= cn * (1 << p);
            ans1 += cn;
            p--;
            ip++;
        }
    }
    int ans2 = 1;
    for(int i = 1; i <= 60; i++){
        if(t[i].empty()) continue;
        int sum = 0;
        for(auto x: t[i]) sum += x;
        if(sum >= mod) {ans2 = 0;break;}
        int res = fact[sum];
        for(auto x: t[i]) res = res * infact[x] % mod;
        ans2 = ans2 * res % mod;
    }
    cout << ans1 << " " << ans2 << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}