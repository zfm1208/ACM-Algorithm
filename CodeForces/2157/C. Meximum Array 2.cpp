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
    int n,k,q; cin >> n >> k >> q;
    vector<pii> p1,p2;
    for(int i = 1; i <= q; i++){
        int c,l,r; cin >> c >> l >> r;
        if(c == 1){
            p1.pb({l,r});
        }else{
            p2.pb({l,r});
        }
    } 
    vector<int> v1(n+1),v2(n+1),ans(n+1,-1);
    for(auto &[l,r] : p1){
        rep(i,l,r) v1[i] = 1;
    }
    for(auto &[l,r] : p2){
        rep(i,l,r) v2[i] = 1;
    }
    for(int i = 1; i <= n; i++)
	{
		if(v1[i] && v2[i]) ans[i] = k + 1;
		else if(v1[i] && !v2[i]) ans[i] = k;
		else if(!v1[i] && !v2[i]) ans[i] = k + 1;
	}
	for(int i = 1,x = 0; i <= n; i++)
	{
		if(ans[i] == -1) ans[i] = x++;x %= k;
	}
    rep(i,1,n) cout << ans[i] << " \n"[i==n];
}
/*
    被第 1类区间覆盖的位置不能有小于 k的数，需要有 k；
    被第 2类区间覆盖的位置需要有小于 k的数，不能有 k。

    被两类区间都覆盖：此时不能填小于等于 k的数，填 k+1。
    被第 1类区间覆盖但不被第 2类区间覆盖：无脑填 k。
    不被任何区间覆盖：随便填，这里填 k+1。
    对于不被第 1类区间覆盖但被第 2类区间覆盖的位置，
    它们需要满足对于任意第 2类区间内，都有 0∼k−1。
    由于题目保证有解，意味着每个第 2 类区间内都有至少 k 个这种位置,
    在这种位置中按顺序循环填写 0∼k−1 一定满足条件。
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