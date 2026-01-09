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
//int ok(int x) {
//    if((x & (x - 1)) == 0 || ((x & (x + 1)) == 0))return -1;
//    int k = 0;
//    while((1LL << (k + 1)) <= x)k++;
//    return (1 << k) - 1;
//}
int ok(int x) {
    if((x & (x - 1)) == 0 || ((x & (x + 1)) == 0))return -1;
    int k = __bit_width(unsigned (x));
    return (1 << (k-1)) - 1;
}
void solve() {
    int x;cin >> x;
    cout << ok(x) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
