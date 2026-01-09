#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

int dis(pii x, pii y) {
    return abs(x.fi - y.fi) + abs(x.se - y.se);
}
void solve() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<pii> v(n + 1);
    rep(i, 1, n) cin >> v[i].fi >> v[i].se;
    int ans = dis(v[a], v[b]);
    if (k == 0) {
        cout << ans << endl;
        return;
    }
    int s1 = inf, s2 = inf;
    rep(i, 1, k) {
        s1 = min(s1, dis(v[a], v[i]));
        s2 = min(s2, dis(v[b], v[i]));
    }
    cout << min(ans, s1 + s2) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}