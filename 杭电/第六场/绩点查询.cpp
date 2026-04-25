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
    int s1, s2;  cin >> s1 >> s2;
    if(s2 < 45){
        cout << "0.0\n";
        return;
    }
    int S = (3 * s1 + 2 * s2 + 4) / 5;
    double ans;
    if(S >= 95) {
        ans = 5.0;
    }else if(S >= 60) {
        ans = 5.0 - 0.1 * (95 - S);
    }else{
        ans = 0.0;
    }
    cout << fixed << setprecision(1) << ans << "\n";
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