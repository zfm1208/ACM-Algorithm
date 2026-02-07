#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
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

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    sort(a.begin()+1,a.end());
    for(int i = 1; i <= n; i++){
        map<int,int> mp;
        for(int j = 1; j <= n; j++) {
            if((a[j] - a[i] >= 0) && (a[j] - a[i] <= n)){
                mp[a[j] - a[i]] = 1;
            }
        }
        int mex = 0;
        while(mp[mex]) mex++;
        ans = max(ans,mex);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}