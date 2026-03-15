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

void solve(){
    int n; cin >> n;
    vector<int> a;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            a.pb(i);
            if(i*i != n)   a.pb(n/i);
        }
    }
    int ans = 1;
    for(auto x: a){
        if(x != n-x)
        ans = max(ans,__gcd(x,n-x));
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