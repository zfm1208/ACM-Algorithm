//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,x,y; cin >> n >> x >> y;
    vector<int> a(n+1);
    if(n & 1){
        for(int i = 2; i <= n; i += 2) {
            a[i - 1] = 0, a[i] = 1;
        }
        a[n] = 2;
        if(a[x] == 0 && a[y] == 0){
            if(x == n - 1 || x == 1) swap(a[x], a[n]);
            else a[x] = 2;
        }
        if(a[x] == 1 && a[y] == 1){
            if(x == n - 1 || x == 1) swap(a[x], a[n]);
            else a[x] = 2;
        }
    }
    else{
        for(int i = 1; i <= n; i += 2) a[i] = 0, a[i + 1] = 1;
        if(a[x] == 0 && a[y] == 0){
            a[x] = 2;
        }
        if(a[x] == 1 && a[y] == 1){
            a[x] = 2;
        }
    }
    for(int i = 1; i <= n; i ++) cout << a[i] << " ";
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
