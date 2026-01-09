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
int cnt;
//O(log (n))
void mergeSort(vector<pii>& a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    vector<pii> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i].first <= a[j].first) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = temp[i - l];
}
void solve() {
    int n; cin >> n;
    vector<pii> a(n+1);
    rep(i,1,n) cin >> a[i].first >> a[i].second;
    sort(a.begin()+1, a.end(), [](pii x, pii y) {
        return x.second < y.second;
    });
    cnt = 0;
    mergeSort(a, 1, n);
    cout << cnt << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}