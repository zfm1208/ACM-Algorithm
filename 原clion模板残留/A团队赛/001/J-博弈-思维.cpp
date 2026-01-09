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
int op = 1;
void solve() {
    cout << "Case " << op++ << ": ";
    int n; cin >> n;
    vector<pii> a(n+10);
    vector<int> b(n+10);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
        b[i] = a[i].fi;
    }
    sort(a.begin() + 1, a.begin() + 1 + n,[](pii x, pii y){
        return x.fi < y.fi;
    });
    int sum = 0;
    b[0] = b[n+1] = -1;
    for(int i = 1; i <= n; i++){
        int pos = a[i].se;
        int mx = -1;
        if(b[pos-1] > b[pos] && b[pos] < b[pos + 1]){
            b[pos] = 0;
            sum += a[i].fi - b[pos];
            continue;
        }
        if(b[pos-1] < b[pos]) mx = max(mx, b[pos-1]);
        if(b[pos+1] < b[pos]) mx = max(mx, b[pos+1]);
        b[pos] = mx + 1;
        sum += a[i].fi - b[pos];
    }
    if(sum & 1) cout << "Alice" << endl;
    else cout << "Bob" << endl;}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}