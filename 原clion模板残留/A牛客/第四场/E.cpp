#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int N = 1e3 + 5;
int n, m;
int a[N][N];
int dj1[2*N];
int dj2[2*N];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    memset(dj1, 0, sizeof(dj1));
    memset(dj2, 0, sizeof(dj2));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dj1[i - j + m] += a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dj2[i + j] += a[i][j];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int sum = dj1[i - j + m] + dj2[i + j] - a[i][j];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}