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
    vector<int> a(n),b(n),c(n);
    rep(i,0,n-1) cin >> a[i];
    rep(i,0,n-1) cin >> b[i];
    rep(i,0,n-1) cin >> c[i];
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i <= n-1; i++){
        bool ok = 1;
        for(int j = 0; j <= n-1; j++){
            if(a[j] >= b[(i+j)%n]){
                ok = 0;
                break;
            }
        }
        if(ok) cnt++;
    }
    // cout << cnt << endl;
    int cnt1 = 0;
    for(int i = 0; i <= n-1; i++){
        bool ok = 1;
        for(int j = 0; j <= n-1; j++){
            if(b[j] >= c[(i+j)%n]){
                ok = 0;
                break;
            }
        }
        if(ok) cnt1++;
    }    
    // cout << cnt1 << endl;
    ans = cnt*cnt1 * n;
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