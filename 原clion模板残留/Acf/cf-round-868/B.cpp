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
    vector<int> a(n+1),c(n+1);
    rep(i,1,n) cin >> a[i],c[i] = abs(a[i] - i);
    sort(c.begin() + 1,c.end());
    int pos = -1;
    rep(i,1,n)if(c[i]!=0){pos = i;break;}
    if(pos == -1){cout << 0 << endl;return;}
    int gcd = 0;
//    rep(i,1,n) cout << c[i] << " ";cout << endl;
    for(int i = pos; i <= n; i ++){
        gcd = __gcd(gcd,c[i]);
    }
    if(gcd % k == 0){cout << 0 << endl;return;}
//    cout << gcd << endl;
    int ans = 0;
    rep(i,pos,n){
        if(c[i] % k!=0) ans++;
    }
    if(ans==2) cout<<"1\n";
    else if(ans>2) cout<<"-1\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
