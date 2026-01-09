#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
void solve() {
    int n, t, k;
    cin >> n >> t >> k;
    int s = n - k;
    if(s < t){
        cout << 0 << endl;
    }else{
        int ans = min(s / t, k + 1);
        cout << ans << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
