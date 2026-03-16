#include<bits/stdc++.h>
using namespace std;
#define intg long long


void solve(){
    int n,m; cin >> n >> m;
    int mx = min(n,m);
    int ans = mx;
    n -= mx;
    m -= mx;
    int op = max(n,m);
    ans += (op + 1) / 2;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}