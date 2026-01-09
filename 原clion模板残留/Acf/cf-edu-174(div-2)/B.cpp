//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1,vector<int>(m + 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> c(n * m + 100, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            c[a[i][j]] = max(c[a[i][j]], 1LL);
            if(i && a[i][j] == a[i - 1][j]) c[a[i][j]] = 2;
            if(j && a[i][j] == a[i][j - 1]) c[a[i][j]] = 2;
        }
    }
    sort(c.begin(), c.end());
    int ans = 0;
    for(int i = 0; i < c.size() - 1; i++) {
        ans += c[i];
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
