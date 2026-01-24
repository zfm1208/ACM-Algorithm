#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define ld long double
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
    vector<pair<ld,int>> ta(n+1);
    for(int i = 1; i <= n; i++){
        cin >> ta[i].fi >> ta[i].se;
    }
    sort(ta.begin()+1,ta.end(),[](auto x, auto y){
        return x.fi < y.fi;
    });
    vector<pair<ld,int>> a;
    a.pb({-1.0,0});
    for(int i = 1; i <= n; i++){
        if(i > 1 && abs(ta[i].fi - ta[i-1].fi) < 1e-9){
            a.back().se += ta[i].se;
        }else a.pb(ta[i]);
    }
    n = a.size() - 1;
    vector<int> pre(n+2, 0), suf(n+2, 0);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i].se;
    }
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1] + a[i].se;
    }
    ld ans = -2e18;
    auto calc = [&] (int i, int j) -> ld {
        ld outbc = 0, getbc = pre[i];
        ld outbu = 0, getbu = suf[j];
        if(i > 0){
            if(1.0 - a[i].fi < 1e-9) outbc = inf;
            else outbc = pre[i] / (1.0 - a[i].fi);
        }
        if(j <= n){
            if(a[j].fi < 1e-9) outbu = inf;
            else outbu = suf[j] / a[j].fi;
        }
        return getbu + getbc - max(outbu, outbc);
    };
    for(int i = 0; i <= n; i++){ // 枚举左端点i
        int l = i + 1,r = n + 1; // 划分右端点范围，三分进行压缩求峰值点
        while(r - l > 2){
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if(calc(i,m1) < calc(i,m2)){
                l = m1;
            }else r = m2;
        }
        for(int k = l; k <= r; k++){
            ans = max(ans,calc(i,k));
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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