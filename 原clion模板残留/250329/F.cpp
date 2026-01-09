//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int x,y,r,vx,vy;
    cin >> x >> y >> r >> vx >> vy;
    int lx,ly,rx,ry;
    cin >> lx >> ly >> rx >> ry;
    if(x+r <=rx && x-r >= lx && y+r <= ry && y-r >= ly){cout << "Yes" << endl;return;}
    int sx = (lx+rx)/2,sy = (ly+ry)/2;
    if(vx == 0 && x - r < lx){cout << "No" << endl;return;}
    if(vx == 0 && x + r > rx){cout << "No" << endl;return;}
    if(vy == 0 && y - r < ly){cout << "No" << endl;return;}
    if(vy == 0 && y + r > ry){cout << "No" << endl;return;}
    double l1 = -1e18;
    double h1 = 1e18;
    //左
    if(vx != 0){
        double x1 = 1.0*(lx - x + r) / vx;
        (vx > 0)? l1 = max(l1, x1) : h1 = min(h1, x1);
    }
    //右
    if(vx != 0){
        double x1 = 1.0*(rx - x - r) / vx;
        (vx > 0)? h1 = min(h1, x1) : l1 = max(l1, x1);
    }
    //下
    if(vy != 0){
        double c = (ly - y + r) * 1.0 / vy;
        (vy > 0) ? l1 = max(l1, c) : h1 = min(h1, c);\
    }
    //上
    if(vy != 0){
        double d = (ry - y - r) * 1.0 / vy;
        (vy > 0) ? h1 = min(h1, d) : l1 = max(l1, d);
    }
    if(l1 > h1 + 1e-14){
        cout << "No" << endl;
        return;
    }
    double s2 = max(l1, 0.0);
    if (s2 <= h1 + s2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}