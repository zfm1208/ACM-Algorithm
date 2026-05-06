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
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0;
    sort(a.begin()+1,a.end(),[](pii x, pii y){
        return x.fi < y.fi;
    });
    for(int l = 1, r = n;  l < r; ){
        int mn = min(a[l].second, a[r].second);
        ans += mn * (a[r].first - a[l].first);
        a[l].second -= mn;
        a[r].second -= mn;
        if(a[l].second == 0) l++;
        if(a[r].second == 0) r--;
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