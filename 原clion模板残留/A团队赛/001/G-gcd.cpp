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

int op=0;
void solve() {
    int n; cin >> n;
    vector<int> a(N);
    vector<int> del(N);
    int gcd = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        gcd = __gcd(gcd,a[i]);
    }
    op++;
    if(gcd > 1){
        cout << "Case " << op << ": " << 0 << endl;
        return;
    }
    sort(a.begin()+1,a.begin()+1+n);
    int k = 0;
    for(int i = 2; i <= n; i ++) {
        k ++;
        del[k] = a[i] - a[i - 1];
    }
    gcd= del[1];
    for(int i = 2; i <= k; i ++) {
        gcd = __gcd(gcd, del[i]);
    }
    if(gcd == 0){
        if(a[1] == 1) cout << "Case " << op << ": "  "1" << endl;
        else cout << "Case " << op << ": "  "0" << endl;
        return;
    }
    if(gcd == 1){
        cout << "Case " << op << ": " << "-1" << endl;
        return;
    }
    int oxo = gcd;
    for(int i = 2; i * i <= gcd; i++){
        if(gcd % i == 0){
            oxo = i;
            break;
        }
    }
    int ans = a[1] % oxo;
    if(ans != 0) ans = oxo - ans;
    cout << "Case " << op << ": " << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}