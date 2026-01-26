#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define ld long double
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
    ld n,d,h; cin >> n >> d >> h;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ld ans = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] - a[i-1] > h){
            ans += d*h/2.0;
        }else{
            ld d1 = (h - (ld)(a[i] - a[i-1])) * 1.0 * d / h;
            ans += 1.0 * (d1 + d) * (a[i] - a[i-1])  / 2.0;
        }
    }
    ans += d * h / 2.0;
    cout << fixed << setprecision(6) << ans << endl;
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