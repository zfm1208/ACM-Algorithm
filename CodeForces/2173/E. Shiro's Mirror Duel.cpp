#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
// #define endl '\n'
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
    vector<int> p(n+1),pos(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        pos[p[i]] = i;
    }
    auto ask = [&](int x,int y) {
        cout << "? " << x << " " << y << endl;
        int u,v; cin >> u >> v;
        if(u == -1) exit(0);
        int u1 = p[u], v1 = p[v];
        swap(p[u],p[v]);
        pos[u1] = v,pos[v1] = u;
    };
    int l = 1,r = n;
    for(int l = 1l; l <= n/2; l++){
        int r = n-l+1;
        while(1){
            int u = pos[l],v = pos[r];
            // cout << u << " " << v << endl;
            if(u == l && v == r) break;
            else if(u == r && v == l) ask(l,r);
            else if(u == l && v != r) ask(v,r);
            else if(u != l && v == r) ask(u,l);
            else ask(u,l);
        }
    }
    cout << "!" << endl;
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