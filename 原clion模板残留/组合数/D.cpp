#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e5 + 5;
int mod = 998244353;
int fact[N],Vfact[N];
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
int comb(int n,int m){
    return fact[n] * Vfact[m] % mod * Vfact[n - m] % mod;
}
void init(){
    for(int i = 0; i <= N; i++){
        if(!i) fact[i] = 1,Vfact[i] = 1;
        else fact[i] = (fact[i - 1] * i) % mod
        ,Vfact[i] = Vfact[i - 1] * ksm(i,mod-2) % mod;
    }
}
void solve() {
    int n,m; cin >> n >> m;
    cout <<( (comb(n,m) % 2 == 0) ? 0 : 1) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while (T--) solve();
    return 0;
}
