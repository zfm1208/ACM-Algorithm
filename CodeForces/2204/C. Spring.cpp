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
    int a,b,c,m; cin >> a >> b >> c >> m;
    auto get_lcm = [&] (int x, int y) -> int {
        if(x == 0 || y == 0) return 0;
        return x / gcd(x,y) * y;
    };
    int lcm = get_lcm(a,get_lcm(b,c));
    // cout << lcm << endl;

    int allA = m / a;
    int allB = m / b;
    int allC = m / c;

    int cntABC = m / lcm;
    int cntA = allA - m / get_lcm(a,b) - m / (get_lcm(a,c)) + cntABC;
    int cntB = allB - m / get_lcm(b,a) - m / (get_lcm(b,c)) + cntABC;
    int cntC = allC - m / get_lcm(a,c) - m / (get_lcm(b,c)) + cntABC;

    int cntAB = m / (get_lcm(a,b)) - cntABC;
    int cntAC = m / (get_lcm(a,c)) - cntABC;
    int cntBC = m / (get_lcm(b,c)) - cntABC;

    int ansA = cntA * 6 + (cntAB + cntAC) * 3 + cntABC * 2;
    int ansB = cntB * 6 + (cntAB + cntBC) * 3 + cntABC * 2;
    int ansC = cntC * 6 + (cntBC + cntAC) * 3 + cntABC * 2;
    cout << ansA << " " << ansB << " " << ansC << endl;
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