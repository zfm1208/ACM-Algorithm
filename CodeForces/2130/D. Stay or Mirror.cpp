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
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    a[n] = 2*n - a[n];
    for(int i = n-1; i >= 1; i--){
        int sum1 = 0,sum2 = 0;
        for(int j = 1; j < i; j++){
            if(a[i] < a[j]) sum1++;
            if(2*n-a[i] < a[j]) sum2++;            
        }
        for(int j = i+1; j <= n; j++){
            if(a[i] > a[j]) sum1++;
            if(2*n-a[i] > a[j]) sum2++;
        }
        a[i] = (sum1 < sum2) ? a[i] : 2*n-a[i]; 
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i] < a[j]) ans++;
        }
    }
    cout << ans << endl;
    
}
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