#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    int ans =0 ;
    for(int i = n; i <= n + 24; i++){
        ans += i;
    }
    cout << ans;
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