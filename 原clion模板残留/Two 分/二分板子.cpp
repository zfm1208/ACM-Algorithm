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
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 10;
    cout << "x: " << x << endl;
    // 找小于x的最大值 =>
    int l = 1, r = 10;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] < x) l = mid;
        else r = mid - 1;
    }
    cout << "小于x的最大值: " << a[r] << endl;

    // 找小于等于x的最大值 =>
    l = 1, r = 10;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    cout << "小于等于x的最大值: " << a[r] << endl;

    // 找大于x的最小值 =>
    l = 1, r = 10;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] > x) r = mid;
        else l = mid + 1;
    }
    cout << "大于x的最小值: " << a[r] << endl;

    // 找大于等于x的最小值 =>
    l = 1, r = 10;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    cout << "大于等于x的最小值: " << a[r] << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}