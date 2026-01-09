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
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 1e6 + 5;


void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    sort(a.begin()+1,a.end());
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i];
    double ave = sum*1.0/n*1.0;
    int ans = 0;
    for(int i = 1; i <= n; i++) if(a[i] > ave)ans++;
//    cout << ans << endl;
    for(int i = n; i > 1; i--){
        sum -= a[i];
        ave = sum*1.0/((i-1)*1.0);
        int l = 1, r = i;
        while(l < r){
            int mid = (l + r) >> 1;
            if((double)a[mid] > ave) r = mid;
            else l = mid+1;
        }
        ans = max(ans,i-l);
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}