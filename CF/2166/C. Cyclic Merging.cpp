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
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int mx = 0 , sum = 0;
    for(int i = 0; i < n; i++){ 
        int t = max(v[i],v[(i+1) % n]);
        sum += t;
        mx = max(mx,t);
    }
    cout << sum - mx << '\n';
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