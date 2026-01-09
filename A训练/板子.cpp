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
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int fact[N];
int invfact[N];
void init(){
    fact[0] = 1;
    for(int i = 1; i <= N-1; i++){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[N-1] = ksm(fact[N-1],mod-2);
    for(int i = N-2; i >= 0; i--){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }
}
int C(int a, int b){
    if(a < b || a < 0) return 0;
    return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
}

void solve(){

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