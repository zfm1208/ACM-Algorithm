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
double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
// a[i] --> a[i] + d == x   a[j] --> a[j] + d == y
// 假设a[i] <= a[j]
// gcd(x,y) == k  x == m1*k y == m2*k
// y - x == (m2-m1)*k
// a[j] - a[i] == (m2-m1)*k
// a[j] - a[i] 的差最大即可
void solve() {
    int n;cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    sort(a.begin()+1,a.end());
    cout << a[n] - a[1] << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
