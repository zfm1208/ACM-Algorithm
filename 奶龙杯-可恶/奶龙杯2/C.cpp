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
const int N = 1e6, mod = 998244353, inf = 1e18;
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}    
/*
A:  6 6 8 4 5 6 8 8
p[]:2 6 7 1 3 4 8 5 
i:  1 2 3 4 5 6 7 8 
B:  1 2 3 4 5 6 7 8
A_i > i : 固定边,p[i]固定
A_i = i : 自由边
A_i < i : 不合法
*/
void solae(){ 
    int n; cin >> n; 
    vector<int> a(n+1);
    bool ok = 0; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < i){ 
            ok = 1;
        }
    }
    if(ok){cout << 0 << endl; return;}
    vector<int>lst(n+1), bj(n+1);
    rep(i,1,n) lst[i] = i;
    map<int,int> p; 
    for(int i = n; i >= 1; i--){ 
		p[i] = lst[a[i]]; 
		if(i != a[i]){ 
			bj[p[i]] = 1; 
		}
		lst[a[i]] = i; 
	}
    vector<int> vis(n+1);
	for(int i = 1; i <= n; i++){
		if(a[i] == i || vis[i]) continue; 
		int u = i;
		while(p[u] != u){ 
			vis[u] = 1; 
			if(p[u] > a[i]){ 
				cout << 0 << endl;
				return;
			}
			u = p[u]; 
		}
	}
	int cnt = 0;//可供分配的数字
    int ans = 1;
	for(int i = 1; i <= n; i++){
		cnt = cnt - bj[i] + 1;
		if(a[i] == i){ 
			ans = ans * cnt % mod; 
			cnt--; 
		}
	}
	cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solae();
    return 0;
}