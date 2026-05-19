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
/*
    0 1 2 4 6 10 
    9 6 3 2 1 0

    10 12 19 53 75
    95 84 75 67 34

    1 2 3 4 5
    3 4 2 1 6
*/
struct node{
    int x, y; // x政治含量,y文化含量
};
void solve(){
    int n; cin >> n;
    vector<node> a(n+1);
    rep(i,1,n) cin >> a[i].x;
    rep(i,1,n) cin >> a[i].y;
    sort(a.begin()+1, a.begin()+1+n, [](node op1, node op2){
        if(op1.x != op2.x) return op1.x < op2.x;
        return op1.y < op2.y;
    });

    int j = 1;
    for(int i = 2; i <= n; i++){
        if(a[i].y >= a[j].y) continue;
        a[++j] = a[i];
    }
    n = j;
    // x 递增 y 递减
    int mn = inf;
    for(int i = 1; i <= n; i++){
        mn = min(mn, a[i].x + a[i].y);
    }
    int m; cin >> m;
    vector<int> tx(m+1), ty(m+1), d(m+1);
    rep(i,1,m) cin >> tx[i];
    rep(i,1,m) cin >> ty[i];
    rep(i,1,m) cin >> d[i];

    auto f = [&] (int x, int tx, int d) -> int {
        if(x < tx) return 0;
        return min(x, tx + d);
    };

    for(int i = 1; i <= m; i++){
        int ans = mn;
        ans = min(ans, f(a[1].x, tx[i], d[i]) + f(a[1].y, ty[i], d[i]));
        ans = min(ans, f(a[n].x, tx[i], d[i]) + f(a[n].y, ty[i], d[i]));
        
        int l = 1, r = n, res1 = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid].x < tx[i]) {
                res1 = mid;  
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        if(res1 != -1) ans = min(ans, f(a[res1].x, tx[i], d[i]) + f(a[res1].y, ty[i], d[i]));

        l = 1, r = n; 
        int res2 = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid].y < ty[i]) {
                res2 = mid;  
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(res2 != -1) ans = min(ans, f(a[res2].x, tx[i], d[i]) + f(a[res2].y, ty[i], d[i]));        
        cout << ans << endl;
    }
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