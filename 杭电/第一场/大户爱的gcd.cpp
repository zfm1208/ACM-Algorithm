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
    int n,m,q; cin >> n >> m >> q;
    vector<int> a(n+1,1);
    for(int i = 1; i <= m; i++){
        int x,y,g; cin >> x >> y >> g;
        if(__gcd(a[x],g) != g) {
            a[x] *= (g / __gcd(a[x],g));
        }
        if(__gcd(a[y],g) != g) {
            a[y] *= (g / __gcd(a[y],g));
        }
    }
    while(q--){
        int x,y; cin >> x >> y;
        cout << __gcd(a[x],a[y]) << endl;
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