//https://ac.nowcoder.com/acm/contest/95334/D
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
    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;
    int ans = 0;
    for (int ch = 0; ch < 26; ch++) {
        int pre = 0, net = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] != ch + 'a') continue;
            if (pre != 0) {
                ans = max(ans, n - i + 1);
            }
            pre = i;
        }
        for (int i = n; i >= 1; i--) {
            if (s[i] - 'a' != ch) continue;
            if (net != 0) {
                ans = max(ans, i);
            }
            net = i;
        }
    }
    cout << (ans == 1 ? 0 : ans) << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
