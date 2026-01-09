#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int, int>
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
vector<double> a(N);
int n,f;
bool check(double x){
    int cnt = 0;
    rep(i,1,n) cnt += (int)(a[i] / x);
    return cnt >= f;
}
void solve() {
    cin >> n >> f; f++;
    double mi = inf, mx = -inf;
    rep(i, 1, n){
        int ri;cin >> ri;
        a[i] = pi * ri * ri;
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }
    double l=0,r=mx;
    double ans = 0;
    while(r - l > 1e-6){
        double mid = (l + r) / 2;
        if(check(mid))ans = mid,l = mid;
        else r = mid;
    }
    printf("%.4f\n",ans);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}