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
const int N = 1e6, mod = 1e9+7;
const double inf = 1e18 + 5;
int op;

void solve() {
    double w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    double ans = inf;
    double e[4][4] = {
        {w1, h1, w2, h2},
        {h1, w1, w2, h2},
        {w1, h1, h2, w2},
        {h1, w1, h2, w2}
    };
    for(int i = 0; i < 4; i++){
        auto [a,b,c,d] = e[i];
        double ex = 0;
        if (b < d) {
            ex = 0.5 * a * (d - b); 
        } else {
            ex = 0.5 * c * (b - d);
        }
        ans = min(ans, a * b + c * d + ex);
    }
    cout << "Case " << ++op << ": " << fixed << setprecision(1) << ans << endl;
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