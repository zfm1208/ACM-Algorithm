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
    vector<pii> a(n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin()+1,a.end(),[](pii x, pii y){
        return x.fi < y.fi;
    });
    for(int i = 1; i <= n; i++){
        ans = max(ans, a[i].fi) + a[i].se;
    }
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