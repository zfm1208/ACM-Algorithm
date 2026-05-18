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
    int n; cin >> n;    
    vector<double> x(n+1), y(n+1), r(n+1);
    double mnx = 1e9, mxx = -1e9, mny = 1e9, mxy = -1e9;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> r[i];
        mnx = min(mnx, x[i] - r[i]);
        mxx = max(mxx, x[i] + r[i]);
        mny = min(mny, y[i] - r[i]);
        mxy = max(mxy, y[i] + r[i]);
    }
    int cnt = 0;
    double eps = 1e-7;
    for(double px = mnx; px <= mxx + eps; px += 0.005){
        for(double py = mny; py <= mxy + eps; py += 0.005){
            for(int i = 1; i <= n; i++) {
                double dx = px - x[i];
                double dy = py - y[i];
                if(dx * dx + dy * dy <= r[i] * r[i]){
                    cnt++;
                    break;
                }
            }
            
        }
    }
    double ans = cnt * (0.005 * 0.005);
    cout << fixed << setprecision(6) << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T; 
    while(T--)
        solve();
    return 0;
}