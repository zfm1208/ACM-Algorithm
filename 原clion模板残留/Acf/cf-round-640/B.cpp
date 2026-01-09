//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    int n1 = n - (k - 1);
    if (n1 > 0 && n1 % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; ++i) cout << "1 ";
        cout << n1 << endl;
        return;
    }
    int n2 = n - 2 * (k - 1);
    if (n2 > 0 && n2 % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; ++i) cout << "2 ";
        cout << n2 << endl;
        return;
    }
    cout << "NO" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
