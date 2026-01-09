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
const int N = 2e6+5, mod = 1e9+7, inf = 1e18 + 5;
const int base = 133;
int p[N], hx[N], hx2[N];
int n;
string s, ss;
void init(){     
    p[0] = 1;
    for(int i = 1; i <= 2*n; i++){
        p[i] = (p[i-1] * base) % mod;
        hx[i] = (hx[i-1] * base + s[i] - 'a' + 1) % mod;  
        hx2[i] = (hx2[i-1] * base + ss[i] - 'a' + 1) % mod; 
    }
}
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int get_hash1(int l, int r){
    if(l > r) return 0; 
    return (hx[r] - hx[l-1] * p[r-l+1] % mod + mod) % mod;
}

int get_hash2(int l, int r){
    if(l > r) return 0;
    return (hx2[r] - hx2[l-1] * p[r-l+1] % mod + mod) % mod;
}
void solve() {
    cin >> n >> s;
    s = " " + s; 
    ss = s;
    reverse(ss.begin() + 1, ss.end()); 
    init();
    for(int i = 0; i <= n; i++){
        int l = i + 1;   
        int r = i + n;           
        int hash1 = get_hash1(1, i);
        int hash2 = get_hash2(n - i + 1, n);
        int h1 = get_hash1(r + 1, 2 * n);
        int h2 = get_hash2(n + 1, 2 * n - i);
        if(h1 == h2 && hash1 == hash2){
			string ans = s.substr(l, n); 
			reverse(ans.begin(), ans.end());
			cout << ans << endl << i << endl;
			return;
		}
    }    
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}