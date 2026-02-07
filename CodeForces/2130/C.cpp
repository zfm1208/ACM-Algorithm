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
    // 尽可能构造一个没有环的图
    int n; cin >> n;
    vector<int> L(2*n+1),id(2*n+1);
    for(int i = 1; i <= n; i++){
        int l,r; cin >> l >> r;
        if(L[l] < r){
            L[l] = r;
            id[l] = i;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= 2*n; i++){
        if(id[i]) ans.pb(id[i]);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size()-1];
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