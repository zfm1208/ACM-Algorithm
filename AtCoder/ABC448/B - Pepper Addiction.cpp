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
    vector<int> c(m + 1);
    for (int j = 1; j <= m; j++){
        cin >> c[j];
    }
    vector<int> sum(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a,b;cin >> a >> b;
        sum[a] += b; 
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans += min(c[j], sum[j]);
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}