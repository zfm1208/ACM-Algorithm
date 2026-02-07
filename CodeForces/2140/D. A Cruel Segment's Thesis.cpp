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
    vector<pii> a(n+1);
    int s = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        s += (a[i].se - a[i].fi);
        sum += a[i].se;
    }
    sort(a.begin()+1,a.begin()+1+n,[](pii x, pii y){
        return x.fi + x.se < y.fi + y.se;
    });
    int op = 0;
    for(int i = 1; i <= n/2; i++){
        op += a[i].fi + a[i].se;
    }
    if(n%2==0){
        cout << s + sum - op << endl;
        return;
    }else{
        int ans = 0;
        int ll = a[n/2+1].fi,rr = a[n/2+1].se;
        for(int i = 1; i <= n; i++){
            int l = a[i].fi, r = a[i].se;
            if(i <= n/2){
                int tp = op - (l+r) + (ll+rr);
                ans = max(ans,sum - tp - r);
            }else{
                ans = max(ans,sum - op - r);
            }
        }
        cout << ans + s << endl;
    }
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