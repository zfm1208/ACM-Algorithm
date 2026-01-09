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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve() {
	int n; cin >> n;
    vector<int> a(n+2),b(n+2);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    sort(a.begin()+1,a.begin()+1+n);
    sort(b.begin()+1,b.begin()+1+n);
    int p = -1;
    for(int i = 2; i <= n; i++){
        if(a[i] - a[i-1] < b[1]){
            p = i;
        }
    }
    if(p == -1){
        cout << "Bob" << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        int l = b[i] - a[p];
        int r = b[i] + a[p];
        auto pl = upper_bound(a.begin()+1,a.begin()+1+n,l);
        auto pr = lower_bound(a.begin()+1,a.begin()+1+n,r);
        int p1 = pl - a.begin();
        int p2 = pr - a.begin();
        p2--;
        if(p1 > p2 || (p1 == p2 && p1 == p)){
            cout << "Bob" << endl;
            return;
        }
    }
    cout << "Alice" << endl;

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