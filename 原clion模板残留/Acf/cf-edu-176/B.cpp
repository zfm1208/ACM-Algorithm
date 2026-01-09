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

void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    if(k == 1){
        int mx = a[1] + a[n];
        for(int i = 2; i < n; i++) mx = max(mx,a[i] + max(a[1],a[n]));
        cout << mx << endl;
        return;
    }
    sort(a.begin()+1,a.end(),greater<int>());
    int sum = 0;
    for(int i = 1; i <= k+1; i++) sum += a[i];
    cout << sum << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
