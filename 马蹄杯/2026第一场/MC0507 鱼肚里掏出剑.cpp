#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    vector<vector<int>> sum(n+1,vector<int>(m+1));
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int l = 0; l <= n; l++)
            {
                int ex = i+l; if(ex > n) break;;
                for(int k = 0; k <= m; k++)
                {
                    int x = i,y = j;
                    int ey = j+k;
                    if(ey > m) break;
                    int cnt1 = sum[ex][ey] - sum[ex][y-1] - sum[x-1][ey] + sum[x-1][y-1];
                    int cnt0 = (ex - x + 1 ) * (ey - y + 1) - cnt1;
                    if(cnt1 > cnt0) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}