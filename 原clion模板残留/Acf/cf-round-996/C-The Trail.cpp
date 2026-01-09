#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1005][1005],row[1005],col[1005],n,m;
string s;
// x == 0
void solve() {
    cin >> n >> m;
    cin >> s;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    int nx = 1,ny = 1;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'D') {
            a[nx][ny] = -row[nx];
            row[nx] += a[nx][ny];
            col[ny] += a[nx][ny];
            nx ++;
        }
        else {
            a[nx][ny] = -col[ny];
            row[nx] += a[nx][ny];
            col[ny] += a[nx][ny];
            ny ++;
        }
    }
    a[n][m] = -col[ny];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        solve();
    }
    return 0;
}