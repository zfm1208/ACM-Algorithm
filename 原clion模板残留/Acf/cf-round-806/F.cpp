//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
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

void solve() {
    int n; cin >> n;
    vector<pii> a(n+1);
    rep(i,1,n) cin >> a[i].se, a[i].fi = i;
    vector<pii> b;
    for(int i = 1; i <= n; i++){
        if(a[i].fi > a[i].se) b.pb({a[i].fi,a[i].se});
    }
    sort(b.begin(),b.end(),[](pii x, pii y){
        return x.se < y.se;
    });
    int ans = 0;
    int len = b.size();
    for(int i = 0; i < len; i++){
        int l = 0,r = len-1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(b[mid].se > b[i].fi) r = mid;
            else l = mid + 1;
        }
        if(b[r].se > b[i].fi){
            ans += (len - r);
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
