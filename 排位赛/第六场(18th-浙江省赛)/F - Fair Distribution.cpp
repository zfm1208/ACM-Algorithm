#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7, inf = 1e18;
#define pb push_back

void solve(){
    int n,m; cin >> n >> m;
    if(m%n == 0){
        cout << 0 << endl;
        return;
    }
    if(n > m){
        cout << n - m << endl;
        return;
    }
    // n 只能降, m 只能升
    int ans = inf;
    int t = 1;
    for(int i = n; i >= max(n-1000000,1LL); i--){
        int t = (m + i - 1) / i;
        int cost = (m % i == 0 ? 0 : (i - m%i)) + (n - i);
        // cout << t << " " << cost << endl;
        if(cost > ans) i -= 10000;
        // cout << "t: " << t << endl;
        ans = min(ans,cost);
    }
    // for(int i = 1; i <= min(50000LL,n); i++){
    //     int t = (m + i - 1) / i;
    //     int cost = (m % i == 0 ? 0 : (i - m%i)) + (n - i);
    //     // cout << t << " " << cost << endl;
    //     ans = min(ans,cost);
    // }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}