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

void solve(){
    int n,m; cin >> n >> m;
    vector<pii> a(n+1);
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        b[i] = a[i].fi - a[i].se;
    }
    int ans = 0, now = 0;
    for(int i = 1; i <= n; i++){
        now += a[i].se;
    }
    if(m >= 2 * n - 1) {
        ans = now;
    }
    now += b[n];
    for(int i = 2; i <= n; i++){
        now += b[n - i + 1];
        if(2 * n - i <= m) ans = max(ans, now);
    }
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