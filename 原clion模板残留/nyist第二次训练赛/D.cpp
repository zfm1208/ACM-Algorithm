//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,x; cin >> n >> x;
    vector<int> a(n+1);
    rep(i,1,n)cin >> a[i];
    sort(a.begin() + 1,a.end(),[](int x,int y){
        return x > y;
    });
    rep(i,1,n) if(a[i] == x){
            cout << 1 << endl;
            return;
        }
    if(a[1] > x){
        cout << 2 << endl;
        return;
    }
    int ans = x / a[1] + (x % a[1] != 0);
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
