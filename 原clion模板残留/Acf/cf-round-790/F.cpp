//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    sort(a.begin()+1,a.end());
    int p = 0;
    vector<int> ans(n+1),c(n+1);
    rep(i,1,n){
        int j = i;
        while(a[j] == a[j+1] && j <= n-1) j++;
        ans[++p] = j - i + 1;
        c[p] = a[i];
        i = j;
    }
    int l=-1,r=-1;
    int len = 0;
    for(int i = 1; i <= p; i++){
        int j = i;
        while(ans[j] >=k && ans[j+1] >= k && j+1 <=p && c[j+1] == c[j] + 1)j++;
        if(c[j] - c[i] > len || l == -1){
            if( ans[j] >=  k){
                l = i;
                r = j;
                len = c[j] - c[i];
            }
        }
        i = j;
    }
    if(l != -1)cout << c[l] << " " << c[r] << endl;
    else cout << -1 << endl;
;}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
