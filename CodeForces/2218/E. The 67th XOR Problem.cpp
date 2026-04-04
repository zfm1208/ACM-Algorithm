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
/*
    a b c d e
    1: 删a
     (b^a) (c^a) (d^a) (e^a)
    2. 删(b^a)
     (c^a ^ (b ^ a))  (d^a ^ (b ^ a))  (e^a ^ (b ^ a))
   =>  c^b  d^b   e^b
   3.删(c^b)
    d^b ^ (c ^ b)   e^b ^ (c ^ b)
   => d^c  e^c
   4.删(d^c)
    d^e
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            ans = max(ans, a[i] ^ a[j]);
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