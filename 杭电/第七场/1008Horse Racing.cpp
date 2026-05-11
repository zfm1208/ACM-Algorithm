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
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    int sum = 0; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum = (sum + a[i]) % mod;
    }
    rep(i, 1, n) cin >> b[i];
    int ans = 0;
    int preb = 0; 
    
    for(int i = 1; i <= n; i++) {
        int tot = (a[i] * b[i] % mod) * ksm(2, mod - 2) % mod;
        int res1 = a[i] * preb % mod;
        ans = (ans + (tot + res1) % mod) % mod;        
        preb = (preb + b[i]) % mod;
    }
    ans = ans * ksm(sum % mod, mod - 2) % mod;
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