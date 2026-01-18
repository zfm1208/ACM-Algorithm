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
    int mx = 0,sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += mx;
    }
    int ans = sum;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            swap(a[i], a[j]);
            sum = 0;
            mx = 0;
            for(int k = 1; k <= n; k++){
                mx = max(mx, a[k]);
                sum += mx;
            }
            ans = max(ans, sum);
            swap(a[i], a[j]);            
        }
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