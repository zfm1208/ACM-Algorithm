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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
struct node{
    int l,r,pro;
};
void solve(){
    int n,m; cin >> n >> m;
    vector<node> a(n+1);
    vector<int> dp(m+1),P(m+1,1); 
    for(int i = 1; i <= n; i++){
        int l,r,p,q; cin >> l >> r >> p >> q;
        a[i].l = l,a[i].r = r;
        a[i].pro = p*ksm(q,mod-2) % mod;
        P[l] = P[l] * (1 - a[i].pro + mod) % mod;
    }
    rep(i,1,m) P[i] = P[i-1] * P[i] % mod;
    sort(a.begin()+1,a.begin()+1+n,[](auto x, auto y){
        return x.l < y.l;
    });
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        auto [l,r,p] = a[i];
        int tp = (dp[l-1] * P[r] % mod * ksm(P[l-1],mod-2) % mod) % mod * ksm(1-p+mod,mod-2) % mod * p % mod;
        dp[r] = (dp[r] + tp) % mod;
    }
    cout << dp[m] << endl;
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