//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define pi acos(-1.0)
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
double r,R,H,V;
bool check(double h){
    double v1 = pi * h * (R * R + r * r + R * r) / 3.0;
    return v1 < V;
}
void solve() {
    cin >> r >> R >> H >> V;
    double l1=0,r1=H;
    double ans = 0;
    while(r1 - l1 > 1e-8){
        double mid = (l1 + r1) / 2;
        if(check(mid))ans = mid,l1 = mid;
        else r1 = mid;
    }
    printf("%.6f\n",ans);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
