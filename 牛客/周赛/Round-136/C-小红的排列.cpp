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

int fact[N], inv[N];
void init() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
    inv[N - 1] = ksm(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fact[n] * inv[m] % mod * inv[n - m] % mod;
}
// https://ac.nowcoder.com/acm/contest/130107/C
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int ou = n/2;
    int ji = n - ou;
    int wen = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'j') ji--;
        else if(s[i] == 'o') ou--;
        else wen++;
    }
    if(ji < 0 || ou < 0) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    ans = C(wen,ji) * fact[n-n/2] % mod * fact[n/2] % mod;   
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    // cin >> T;
    while(T--)
        solve();
    return 0;
}