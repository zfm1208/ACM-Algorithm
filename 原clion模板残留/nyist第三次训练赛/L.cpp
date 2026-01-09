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
int a[N],pre[N];
int n,c,d;
bool check(int k){
    int s1 = pre[min(n,k+1)] * (d/(k+1));
    int s2 = pre[min(n,d % (k+1))];
    return s1 + s2 >= c;
}
void solve() {
    cin >> n >> c >> d;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int sum = 0;
    rep(i,1,min(n, d)) sum += a[i];
    rep(i,1,n) pre[i] = pre[i-1] + a[i];
    if(sum >= c){cout << "Infinity"<< endl;return;}
    if(a[1] * d < c){cout << "Impossible" << endl; return;}
    int l = 0,r = d;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid))l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
