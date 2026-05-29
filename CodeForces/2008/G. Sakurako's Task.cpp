#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n,k; cin >> n >> k;
    vii a(n+1);
    int g = 0;
    rep(i,1,n) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    if(n == 1){
        if(a[1] < k) cout << k << endl;
        else cout << k-1 << endl;
        return;
    }
    int l = 0, r = n+k+1;
    int ans = 0;
    // 去找[0,mid]区间缺失的数字个数是否>=k
    auto check = [&](int mid) -> bool {
        int cnt = min(n, mid / g + 1);
        return (mid + 1) - cnt >= k;
    };
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}