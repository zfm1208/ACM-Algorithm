#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
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
    vii a(n+1), b(m+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    int mn = inf;
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    for(int i = 1; i <= n; i++){
        auto pos = lower_bound(b.begin()+1,b.end(),a[i]) - b.begin();
        if(pos <= m) {
            mn = min(mn, abs(a[i] - b[pos]));
        }
        if(pos > 1){
            mn = min(mn, abs(a[i] - b[pos - 1]));
        }
    }
    int mn1 = inf;
    rep(i,1,n) mn1 = min(mn1, abs(a[i]));
    int mn2 = inf;
    rep(i,1,m) mn2 = min(mn2, abs(b[i]));
    int ans = min({mn + mn1 + mn2, 2 * mn1 + 2 * mn, 2 * mn2 + 2 * mn});
    cout << ans << endl;
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