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
    int n,k; cin >> n >> k;
    set<int> st;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        st.insert(x);
    }
    auto tp = st;
    vector<int> ans;
    while(st.size()){
        auto x = *st.begin();
        for(int i = x; i <= k; i+=x){
            if(tp.find(i) == tp.end()){
                cout << -1 << endl;
                return;
            }
            st.erase(i);
        }
        ans.pb(x);
    }
    cout << ans.size() << endl;
    for(auto x: ans) cout << x << " ";
    cout << endl;
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