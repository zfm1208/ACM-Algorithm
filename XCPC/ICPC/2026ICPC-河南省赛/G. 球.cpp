#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
// 经典的计算几何题目，核心在于计算三维空间中两个球体的相交体积
void solve(){
    double x,y,z,R,r; 
    cin >> x >> y >> z >> R >> r;
    if(R == 0 || r == 0){
        cout << fixed << setprecision(6) << 0.0 << endl;
        return;
    }
    double d = sqrt(x * x + y * y + z * z);
    // 情况1：两球相离或外切
    if(d >= R + r) {
        cout << fixed << setprecision(6) << 0.0 << endl;
        return;
    }
    // 情况2：两球包含或内切
    if(d <= abs(R - r)){
        double mnr = min(R, r);
        double vol = (4.0 / 3.0) * pi * mnr * mnr * mnr;
        cout << fixed << setprecision(6) << vol << endl;
        return;
    }
    // 情况3：两球部分相交
    double d1 = (R * R - r * r + d * d) / (2.0 * d);
    double d2 = d - d1;

    double h1 = R - d1;
    double h2 = r - d2;

    double v1 = (1.0 / 3.0) * pi * h1 * h1 * (3.0 * R - h1);
    double v2 = (1.0 / 3.0) * pi * h2 * h2 * (3.0 * r - h2);

    cout << fixed << setprecision(6) << (v1 + v2) << "\n";

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