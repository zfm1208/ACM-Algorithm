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
//反例:
//6 3 4
//2 1 2 2 1 2
//sort ->
//1 1 2 2 2 2
int a[N],b[N];
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    int len = r - l + 1;
    int sum1 = 0,sum2 = 0;
    rep(i, 1, n) cin >> a[i],b[i] = a[i];
    sort(a+1,a+1+r);
    rep(i,1,len) {
//        cout << a[i] << " ";
        sum1 += a[i];
    }
    sort(b+l,b+n+1);
    rep(i,l,r) {
//        cout << b[i] << " ";
        sum2 += b[i];
    }
    cout << min(sum1,sum2) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
