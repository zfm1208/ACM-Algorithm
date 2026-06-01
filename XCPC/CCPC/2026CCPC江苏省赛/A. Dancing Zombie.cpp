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
    int n,k; cin >> n >> k;
    vector<pii> a(n+1);
    rep(i,1,n) cin >> a[i].fi >> a[i].se;
    int l = 0, r = inf, ans = 0;
    auto check = [&](int mid) -> bool {
        vector<pii> cun;
        for(int i = 1; i <= n; i++){
            if(a[i].fi <= mid){
                int l = a[i].se - (mid - a[i].fi);
                int r = a[i].se + (mid - a[i].fi);
                cun.push_back({l,r});
            }
        }
        if(cun.empty()) return false;
        sort(cun.begin(), cun.end(), [](pii x, pii y){
            if(x.fi == y.fi) return x.se < y.se;
            return x.fi < y.fi;
        });
        if(cun[0].fi > 0) return false;
        int mx = cun[0].se;
        for(int i = 1; i < cun.size(); i++){
            if(cun[i].fi > mx + 1) {
                return mx >= k;
            }
            mx = max(mx, cun[i].se);
        }
        return mx >= k;
    };
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
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