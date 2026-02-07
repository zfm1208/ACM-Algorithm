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
    vector<int> p(n+1);
    rep(i,1,n) cin >> p[i];
    if(n == 1){cout << 1 << endl; return;}
    int pos = -1;
    if(p[1] == n){
        rep(i,2,n) if(p[i] == n-1) pos = i;
    }else{
        rep(i,2,n) if(p[i] == n) pos = i;
    }
    vector<int> ans;
    auto check = [&] (int r) -> void {
        for(int l = 1; l <= r; l++){
            vector<int> cur;
            for(int k = r+1; k <= n; k++) cur.pb(p[k]);
            for(int k = r; k >= l; k--) cur.pb(p[k]);
            for(int k = 1; k <= l-1; k++) cur.pb(p[k]);
            if(ans.empty() || cur > ans){
                ans = cur;
            }
        }
    };
    if(pos > 1)check(pos-1);
    if(pos == n)check(n);
    rep(i,0,n-1) cout << ans[i] << " \n"[i==n-1];
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