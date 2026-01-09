//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int n,m,x;
int gty(vector<int> &a){
    vector<int> b;
    rep(i,1,a.size()-1) b.pb(a[i]-a[i-1]);
    sort(b.begin(),b.end(),[](int x,int y){
        return x > y;
    });
    if(b.size() == 1) return b[0]-1;
    return max(b[1]-1,(b[0]-1)/2);
}
void solve() {
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(1,0));
    rep(i,1,n){cin >> x;a[x-1].pb(i);}
    rep(i,0,m-1)a[i].pb(n+1);
    int ans = inf;
    rep(i,0,m-1){ans = min(ans,gty(a[i]));}
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
