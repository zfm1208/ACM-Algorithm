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
    vector<int> a(n+1);
    int mx = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        if(i == mx) {
            cnt++;
        }
    }
    if(cnt == 0){
        rep(i,1,n) cout << a[i] << " \n"[i==n];
        return;
    }
    int pos = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == n)pos = i;
    }
    swap(a[pos],a[1]);
    rep(i,1,n) cout << a[i] << " \n"[i==n];
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