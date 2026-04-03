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
const int N = 1e6, mod = 10007, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int cnt = 0;
    vector<int> l(n+1),r(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]) l[i]++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[j] < a[i]) r[i]++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i] == a[j]){
                cnt = (cnt + l[i] * r[j] % mod) % mod;
            }
        }
    }
    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}