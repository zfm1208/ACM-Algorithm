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
void solve1(){
    int n; cin >> n;
    int ans = 0;
    int cur_max = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x >= cur_max){
            ans++;
            cur_max = x;
        }
    }
    cout << ans << endl;
}
void solve(){
    int n; cin >> n;
    vector<pii>a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin()+1,a.end(),[](pii x, pii y){
        if(x.fi == y.fi) return x.se > y.se;
        return x.fi > y.fi;
    });
    int mn = inf;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        // cout << a[i].fi << " "<< a[i].se << endl;
        if(a[i].se == 1) {
            cout << i - cnt << endl;
            return;
        }
        if(a[i].se > mn) cnt++;
        mn = min(mn,a[i].se);
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