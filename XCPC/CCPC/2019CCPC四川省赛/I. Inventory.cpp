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

int op = 0;

void solve() {
    int n; double v; 
    cin >> n >> v;
    double sum = 0;
    for(int i = 1; i <= n; i++){
        double x; cin >> x;
        sum += sqrt(x);
    }
    double ans = (sum * sum) / v;
    cout << "Case " << ++op << ": " << fixed << setprecision(6) << ans << endl;
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