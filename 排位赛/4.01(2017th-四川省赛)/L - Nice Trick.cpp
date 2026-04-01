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
int fact[N], inv[N];
// https://qoj.ac/contest/902/problem/3727
void solve(){
    int n;
    while(cin >> n){
        vector<int> a(n+1);
        rep(i,1,n) cin >> a[i];
        vector<int> p1(n+1),p2(n+1),p3(n+1),p4(n+1);
        for(int i = 1; i <= n; i++){
            p1[i] = (p1[i-1] + a[i]) % mod;
            p2[i] = (p2[i-1] + a[i] * a[i] % mod) % mod;
            p3[i] = (p3[i-1] + a[i] * a[i] % mod * a[i] % mod) % mod;
            p4[i] = (p4[i-1] + a[i] * a[i] % mod * a[i] % mod * a[i] % mod) % mod;
        }
        int S4 = (((ksm(p1[n],4) % mod - (6 * ksm(p1[n],2) % mod * p2[n] % mod) + mod) % mod + (8 * p1[n] % mod * p3[n] % mod) % mod + mod) % mod + (3 * ksm(p2[n],2) % mod) % mod - (6 * p4[n] % mod + mod) + mod) % mod;
        S4 = S4 * ksm(24, mod-2) % mod;
        cout << S4 << endl;;        
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