//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define rep(i,st,ed) for(int i = (st); i <= (ed); i++)
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    rep(i,1,n)
        rep(j,1,m)
            cin >> a[i][j];
    int midx = n/2+ n%2;
    int midy = m/2+ m%2;
    int sum = 0;
    rep(i,1,midx)
        rep(j,1,midy)
        {
            int x1 = a[i][j];
            int x2 = a[i][m-j+1];
            int x3 = a[n-i+1][j];
            int x4 = a[n-i+1][m-j+1];
            priority_queue<int> q;
            q.push(x1), q.push(x2), q.push(x3), q.push(x4);
            q.pop();
            int pos = q.top();
            if(i == n - i + 1 && j == m - j + 1) continue;
            if(i == n - i + 1) {
                sum += abs(pos- x1);
                sum += abs(pos- x2);
            }
            if(j == m - j + 1) {
                sum += abs(pos- x1);
                sum += abs(pos- x3);
            }
            if(i != n - i + 1 && j != m - j + 1) {
                sum += abs(pos- x1);
                sum += abs(pos- x3);
                sum += abs(pos- x2);
                sum += abs(pos- x4);
            }
        }
    cout << sum << endl;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
