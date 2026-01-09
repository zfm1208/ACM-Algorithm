//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
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
void solve() {
    int n,m; cin >> n >> m;
    vector<int> x(n+1),r(n+1);
    rep(i,1,n) cin >> x[i];
    rep(i,1,n) cin >> r[i];
    unordered_map<int, int> mp;
    rep(i,1,n){
        rep(j,-r[i],r[i]){
            int x1 = x[i] + j;
            int y1 = sqrt(r[i] * r[i] - j * j);
            if(mp[x1] < y1){
                mp[x1] = y1;
            }
        }
    }
    int sum = 0;
    for(auto& [_,y]: mp)sum += 2 * y + 1;
    cout << sum << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
