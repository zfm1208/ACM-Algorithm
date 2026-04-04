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
const int N = 5e3+3, mod = 998244353, inf = 1e18 + 5;
// int C[N][N];
// void init(){
//     for(int i = 1; i <= N; i++){
//         C[i][0] = 1;
//         for(int j = 1; j <= i; j++){
//             C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
//         }
//     }
// }
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

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    int ans = 0;
    for(int i = 2; i <= n; i++){
        int d1 = min(a[1], a[i] - a[1]);
        int d2 = min(a[i-1], a[i] - a[i-1]);
        int res = 0;
        if(d1 <= d2){
            res = C(a[i], a[1]); 
        }else{
            res = C(a[i], a[i-1]); 
        }
        ans = (ans + res) % mod;
    }
    cout << ans << endl;
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