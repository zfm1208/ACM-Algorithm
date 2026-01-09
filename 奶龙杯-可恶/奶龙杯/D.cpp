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
int fa[N];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void solve() {
    int n; cin >> n;
    vector<pair<string,string>> a(n+1);
    map<string,int> mp;
    rep(i,1,2*n) fa[i] = i;
    int jl = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
		if(!mp[a[i].fi]){
            jl++;
            mp[a[i].fi] = jl;
        }
		if(!mp[a[i].se]){
            jl++;
            mp[a[i].se] = jl;
        }
		int x = find(mp[a[i].fi]);
        int y = find(mp[a[i].se]);
		if(x==y){
			cout << "No" << endl;
			return;
		}
		fa[x] = y;
    }
    cout << "Yes" << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}