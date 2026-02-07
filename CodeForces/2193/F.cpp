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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    由于只能向右或者向上向下走，我们先将数据根据x排序
    然后最短距离是横坐标的移动距离+纵坐标的移动距离
    横坐标的移动距离是固定的 = [bx - ax]
    最小化y轴上的移动距离即可
        1. 局部思考：处理同一列的点
        如果同一列有很多点，贪心是从最上面走到最下面的点，或反过来
        贡献是maxY - minY

*/
struct node{
    int x, y;
};
void solve(){
    int n,sx,sy,ex,ey;
    cin >> n >> sx >> sy >> ex >> ey;
    vector<node> a(n+1);
    rep(i,1,n) cin >> a[i].x;
    rep(i,1,n) cin >> a[i].y;
    map<int,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        mp[a[i].x].pb(a[i].y);
    }
    int dp0 = 0, dp1 = 0;
    int lmn = sy, lmx = sy;
    for(auto &[x, vc] : mp){
        sort(vc.begin(),vc.end());
        int ndp0 = min(dp1 + abs(lmx - vc.back()), dp0 + abs(lmn - vc.back())) + vc.back() - vc.front();
        int ndp1 = min(dp0 + abs(lmn - vc.front()), dp1 + abs(lmx - vc.front())) + vc.back() - vc.front();
        dp0 = ndp0;
        dp1 = ndp1;
        lmx = vc.back();
        lmn = vc.front();
    }
    int ans = min(dp0 + abs(lmn - ey), dp1 + abs(lmx - ey)) + (ex - sx);
    cout << ans << endl;
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