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
const int N = 1e6 + 5;
unordered_map<int, int> cnt_b, cnt_a;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    cnt_b.clear();
    cnt_a.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) {
        int x; cin >> x;
        cnt_b[x]++;
    }
    int pos = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (cnt_a[x] < cnt_b[x]) {
            pos++;
        }
        cnt_a[x]++;
        if (i > m) {
            int y = a[i - m];
            if (cnt_a[y] <= cnt_b[y]) {
                pos--;
            }
            cnt_a[y]--;
        }
        if (i >= m && pos >= k) {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cnt_a.erase(a[i]);
    }
    for (int j = 1; j <= m; j++) {
        cnt_b.erase(b[j]);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}