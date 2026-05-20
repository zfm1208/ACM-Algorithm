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
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    for(int i = 1; i <= n; i++){
        sort(a[i].begin()+1, a[i].end());
    }
    int ans =0 ;
    for(int i = 1; i <= m; i++){
        int mn = inf;
        for(int j = 1; j <= n; j++){
            mn = min(mn, a[j][i]);
        }
        ans += mn;
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