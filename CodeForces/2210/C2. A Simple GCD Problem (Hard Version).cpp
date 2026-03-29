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

void solve(){
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int cnt = 0;
    vector<int> g(n+1);
    for(int i = 2; i <= n - 1; i++){
        g[i-1] = __gcd(a[i-1], a[i]);
        g[i] = __gcd(a[i], a[i+1]);
        // if(g[i] > g[i-1]) continue;
        // if(a[i-1] == g[i-1] && a[i-1] != 1) continue;
        int gg = lcm(g[i], g[i-1]);
        if(b[i] >  gg) cnt++;
    }
    int g1 = __gcd(a[1], a[2]);
    int gn = __gcd(a[n], a[n-1]);
    if(a[1] != g1 && b[1] != 1) cnt++;
    if(a[n] != gn && b[n] != 1) cnt++;
    cout << cnt << endl;
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