// MIOPP
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve() {
    int n,m,k;
    cin >> n >> k >> m;
    int s = n / k; 
    int les = n - s; 
    int ans = 0;
    if(m <= les){ 
        ans += m;
        ans += (s + 1) / 2; 
    }
    else{ 
        ans += les;
        m -= les;
        s -= m; 
        ans += m;
        ans += (s + 1) / 2; 
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}