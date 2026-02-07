#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e12, mod = 998244353, inf = 1e18 + 5;
void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if(k < y){
        cout << k << endl;
        return;
    }
    auto check =[&](int mid) -> int {
        for (int i = 1; i <= x; i++) {
            mid -= mid / y;
        }
        return mid >= k;
    };
    int ans = -1;
    int l = 1, r = N;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}