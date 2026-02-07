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
const int N = 1e5+10, mod = 998244353, inf = 1e18 + 5;
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
    int n,m,q; cin >> n >> m >> q;
    vector<int> b(m+1);
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    if(b[1] > b[2]) swap(b[1],b[2]);
    while(q--){
        int x; cin >> x;
        if(x > b[1] && x < b[2]) cout << (b[2] - b[1]) / 2 << endl;
        else if(x < b[1])cout << b[1]-1 << endl;
        else cout << n-b[2] << endl;
    }
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