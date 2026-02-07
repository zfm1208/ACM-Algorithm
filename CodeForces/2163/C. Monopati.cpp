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
    int n; cin >> n;
    vector<vector<int>> a(3,vector<int>(n+1));
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int nn = 2 * n;
    vector<int> pre_mn(n + 1), pre_mx(n + 1);
    pre_mn[1] = a[1][1];
    pre_mx[1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        pre_mn[i] = min(pre_mn[i - 1], a[1][i]);
        pre_mx[i] = max(pre_mx[i - 1], a[1][i]);
    }
    vector<int> suf_mn(n + 1), suf_mx(n + 1);
    suf_mn[n] = a[2][n];
    suf_mx[n] = a[2][n];
    for (int i = n - 1; i >= 1; i--) {
        suf_mn[i] = min(suf_mn[i + 1], a[2][i]);
        suf_mx[i] = max(suf_mx[i + 1], a[2][i]);
    }
    vector<pii> p;
    for(int k = 1; k <= n; k++){
        int l = min(pre_mn[k],suf_mn[k]);
        int r = max(pre_mx[k],suf_mx[k]);
        p.pb({l,r});
    }
    sort(p.begin(),p.end(), [&](auto &x, auto &y){
        return x.fi > y.fi;
    });
    priority_queue<int, vector<int>, greater<int>> pq;  
    int ans = 0, i = 0;
    for (int l = nn; l >= 1; l--){  
        while(i < (int)p.size() && p[i].fi == l){  
            pq.push(p[i++].se);
        }
        if(!pq.empty()){
            ans += (nn - pq.top() + 1);
        }
    }
    cout << ans << endl;
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