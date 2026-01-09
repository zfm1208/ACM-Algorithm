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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve(){
    int n; cin >> n;
    vector<pii> s(n+1);
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        cin >> s[i].fi >> s[i].se;
    }
    auto [ll,rr] = s[1];
    int pos = -1;
    for(int i = 1; i <= n; i++){
        auto [l,r] = s[i];
        if(r < ll) {pos = ll; break;}
        if(l > rr) {pos = rr; break;}
        ll = max(ll,l);
        rr = min(rr,r);
    }
    if(pos == -1) pos = ll;
    for(int i = 1; i <= n; i++){
        auto [l,r] = s[i];
        if(pos > r) pos = r;
        if(pos < l) pos = l;
        ans[i] = pos;
    }
    for(int i = n-1; i >= 1; i--){
        auto [l,_] = s[i];
        if(ans[i] > ans[i+1]){
            ans[i] = max(ans[i+1],l);
        }
    }
    rep(i,1,n) cout << ans[i] << " \n"[i==n];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}