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
    int sum = 0;
    for(int i = 1; i < n; i++){
        sum += abs(a[i+1] - a[i]);
    }
    int ans = sum;
    for(int i = 2; i < n; i++){
        int tp = sum;
        ans = min(ans,tp - (abs(a[i-1] - a[i]) + abs(a[i] - a[i+1])) + abs(a[i-1] - a[i+1]));
    }
    ans = min({ans,(sum-abs(a[1] - a[2])),(sum-abs(a[n-1] - a[n]))});
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