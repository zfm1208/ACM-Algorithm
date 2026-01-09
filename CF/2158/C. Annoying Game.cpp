#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int ans = -inf;
    if(!(k&1)){
        int sum = 0;
        rep(i,1,n){
            sum += a[i];
            ans = max(sum,ans);
            sum = max(sum,0LL);
        }
        cout << ans << endl;
        return;
    }
    vector<int> pre(n+1),premn(n+1),sufmx(n+2);
    rep(i,1,n) pre[i] = pre[i-1] + a[i];
    rep(i,1,n) premn[i] = min(premn[i-1],pre[i]);
    sufmx[n] = pre[n];
    for(int i = n - 1; i >= 0; i--) sufmx[i] = max(sufmx[i + 1],pre[i]);
    rep(i, 1, n) ans = max(ans, sufmx[i] - premn[i - 1] + b[i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}