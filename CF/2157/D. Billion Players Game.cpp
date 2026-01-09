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
    // max_ans = sum(|p-ai|) (i: 1~n )
    // F = |p - ai| 凸函数
    int n,l,r; cin >> n >> l >> r;
    vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin()+1, a.begin()+1+n);
	int p = a[(n + 1) / 2];
    p = (p > r) ? r : p;
    p = (p < l) ? l : p; 
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += abs(a[i] - p);
	}
	cout << ans << endl;
}
/*
    1 3 4 6
    p = 3 
    2 + 0 + 1 + 3 = 6
    p = 4
    3 + 1 + 0 + 2 = 6

    1 3 4 6 10
    p = 4
    3 + 1 + 0 + 2 + 6 = 12
    p = 5
    4 + 2 + 1 + 2 + 5 = 14
*/

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