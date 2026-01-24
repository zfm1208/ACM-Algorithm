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
    int n,x; cin >> n >> x;
    vector<array<int,3>> arr(n);
    for(int i = 0; i < n; i++){
        int a,b,c; cin >> a >> b >> c;
        arr[i] = {a,b,c};
    }
    int sum = 0;
    for(auto [a,b,c] : arr){
        sum += (b-1) * a;
    }
    if(sum >= x){
        cout << 0 << endl;
        return;
    }
    int mx = -inf;
    for(auto [a,b,c] : arr){
        mx = max(mx, a-c + (b-1) * a);
    }
    if(mx <= 0){
        cout << -1 << endl;
        return;
    }
    // int ans = ceil(double(x - sum) / (double)mx);
    int ans = (x - sum + mx - 1) / mx;
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