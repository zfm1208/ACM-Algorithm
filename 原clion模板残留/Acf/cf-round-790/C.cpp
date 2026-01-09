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
    int n,m; cin >> n >> m;
    string s[n+1];
    int mn = inf;
    rep(i,0,n-1) cin >> s[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int ans = 0;
            for(int k = 0; k <= m-1; k++){
                ans += abs(s[i][k] - s[j][k]);
            }
            mn = min(ans,mn);
        }
    }
    cout << mn << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
