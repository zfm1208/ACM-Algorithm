#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int l = 1, r = 1, sum = 0, ans = inf;
    while (r <= n) {
        sum += a[r++];
        while (sum >= m) {
            ans = min(ans, r - l);
            sum -= a[l++];
        }
    }
    cout << (ans == inf ? 0 : ans) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}