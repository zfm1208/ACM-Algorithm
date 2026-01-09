//https://ac.nowcoder.com/acm/contest/95334/H
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b - a < d - c) {
        cout << a << " " << c << "\n";
        cout << a << " " << c + 1 << "\n";
        cout << a + 1 << " " << d << "\n";
    } else {
        cout << a << " " << d << "\n";
        cout << a + 1 << " " << d << "\n";
        cout << b << " " << d - 1 << "\n";
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
