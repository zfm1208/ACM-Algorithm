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
int ksm(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

/*
    除了第一个人,剩下的n个人是相互独立的
    算出来其中一个人的概率,然后^n即可
    p = (m-x) / m; p赢占比
    q = ((m-x)/m  + (x-1)/m); 总占比
    p / q = (m-x) / (m-1)
    p / q => p * q ^'998244351' % mod
*/
void solve(){
    int n,m; cin >> n >> m;
    for(int x = 1; x <= m; x++){
        int p = (m-x);
        int q = m-1;
        int ans = (ksm(p,n) * ksm(q,998244351 * n) % mod)% mod;
        cout << ans << " ";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}