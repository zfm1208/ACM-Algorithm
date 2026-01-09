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
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> a(n+5,vector<int>(m+5));
    rep(i,1,k){int x,y;cin >> x >> y;}
    vector<pii>v(k+1);
    rep(i,1,k){cin >> v[i].fi >> v[i].se;}
    string s;
    rep(i,1,n-1) s+="D";
    rep(i,1,m-1) s+="R";
    for(int i = n; i >= 1; i--){
        if ((i&1)==(n&1)) {
            for (int j=m;j>=2;j--) {
                s+="L";
            }
        } else {
            for (int j=1;j<=m-1;j++) {
                s+="R";
            }
        }
        if (i!=1) {s+='U';}
    }
    cout << s.size() << endl;
    cout << s << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
