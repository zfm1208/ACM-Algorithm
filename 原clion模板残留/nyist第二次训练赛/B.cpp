//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define uint unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    int sum=0;
    rep(i,1,n) cin >> a[i], sum+=a[i];
    if(n == 1 || n == 2){
        cout << -1 << endl;
        return;
    }
    sort(a.begin() +1,a.end());
    int ans = a[n/2 + 1] * 2 * n;
    if(sum > ans) cout << 0 << endl;
    else cout << ans - sum + 1 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
