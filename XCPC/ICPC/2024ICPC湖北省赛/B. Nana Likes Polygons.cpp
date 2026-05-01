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
/*
    给你n个点, 找出最小三角形面积,没有输出-1
    三角形面积- 用向量叉积计算面积
*/
void solve(){
    int n; cin >> n;
    vector<pii> a(n+1);
    rep(i,1,n) cin >> a[i].fi >> a[i].se;
    double ans = inf;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
                auto &[x1,y1] = a[i];
                auto &[x2,y2] = a[j];
                auto &[x3,y3] = a[k];
                int s = abs((x2-x1) * (y3-y1) - (x3-x1) *(y2-y1));
                if(s == 0) continue;
                ans = min(ans, (double) s * 1.0 / 2);
            }
        }
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}