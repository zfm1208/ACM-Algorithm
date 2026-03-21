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
// https://ac.nowcoder.com/acm/contest/130418/C
// y = -x*x + b*x + c
void solve(){
    double b,s; cin >> b >> s;
    double a = 1;
    auto get = [&](double x, double c) -> double {
        return -x*x*x/3.0 + b*x*x/2.0 + c*x;
    };
    auto check = [&](double c) -> double {
        double d = b*b + 4.0*a*c;
        if(d <= 0) return 0;
        double sq = sqrt(d);
        double l = max(0.0,(b - sq) / 2);
        double r = (b + sq) / 2;
        if(r > l) return get(r,c) - get(l,c);
        return 0;
    };
    double l = -b * b / 4.0;
    double r = 1e12;    
    for(int i = 0; i < 200; i++){
        double c = (l + r) / 2;
        if(check(c) < s) l = c;
        else r = c;
    }
    cout << fixed << setprecision(11) << l << endl;
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