#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
bool cmp(int x, int y){
    return x < y;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1,0));
    vector<int> sum(n+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
    }
    vector<int> c(n);
    for(int i = 0; i < n; i++) c[i] = i;
    sort(c.begin(), c.end(), [&](int a, int b){
        return sum[a] > sum[b];
    });
    int ans = 0;
    for(int i = 0; i < n; i++){
        int p = c[i];
        for(int j = 0; j < m; j++){
            ans += ((n*m - (i * m + j)) * a[p][j]);
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}