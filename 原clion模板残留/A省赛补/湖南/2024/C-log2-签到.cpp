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
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    // 2^10 == 1024// 2^9 == 512// 2^8 == 256// 2^7 == 128// 2^6 == 64
    // 2^5 == 32// 2^4 == 16// 2^3 == 8// 2^2 == 4// 2^1 == 2// 2^0 == 1
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        sum += log2(x);
    }
    if(!sum) cout << 0 << endl;
    else cout << sum/11 +1 << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}