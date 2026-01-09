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
    int n,m; cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    if(n == 1){cout << "YES" << endl;return;}
    sort(b.begin()+1,b.end());
    a[1] = min(b[1] - a[1],a[1]);
    for(int i = 2; i <= n; i++){
        int l = 1,r = m;
        while(l < r){
            int mid = (l + r) >> 1;
            if(b[mid]-a[i] >= a[i-1]) r = mid;
            else l = mid+1;
        }

        if(b[l]-a[i]>=a[i-1]){
            if(a[i]>=a[i-1]){
                a[i]=min(a[i],b[l]-a[i]);
            }
            else{
                a[i]=b[l]-a[i];
            }
        }
        if (a[i] < a[i - 1]) {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}