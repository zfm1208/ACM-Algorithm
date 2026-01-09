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
const int N = 2e3 + 5;
vector<int>a[N];
void solve() {
    int n,x,y; cin >> n >> x >> y;
    int len = y-x;
        cout << n << endl;
        for(int i = 1; i < n-3; i++)
        cout << n-len+1 << endl;
        cout << 1 << endl << 0 << endl;
//    for(int i = 1; i < n; i++){
//        a[i].pb(i + 1);
//    }
//    for(int i = 2; i <= n; i++){
//        a[i].pb(i - 1);
//    }
//    a[x].pb(y);
//    a[y].pb(x);
//    vector<int> ans(n);
//    for(int i = 1; i < n; i++){
//        int cnt = 0;
//    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
