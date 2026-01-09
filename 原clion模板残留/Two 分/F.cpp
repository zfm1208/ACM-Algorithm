#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; i++)
using namespace std;
const int N = 5e4 + 5;
vector<int> a(N + 2);
int H, n, m;
bool check(int x) {
    int cnt = 0;
    int j = 0;
    for(int i = 1; i <= n + 1; i++){
        if (a[i] - a[j] < x)cnt++;
        else j = i;
    }
    return cnt <= m;
}
void solve() {
    cin >> H >> n >> m;
    rep(i, 1, n) cin >> a[i];
    a[0] = 0,a[n + 1] = H;
    sort(a.begin(), a.begin() + n + 2);
    int l = 1, r = H;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid))l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}