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
    vector<int> a(n+2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    vector<int> pre(n+1),suf(n+2);
    int lst = a[1];
    for(int i = 2; i <= n; i++){
        pre[i] = lst;
        if(a[i] < a[i-1]){
            lst = a[i];
        }
    }
    lst = a[n];
    for(int i = n - 1; i >= 1; i--){
        suf[i] = lst;
        if(a[i] < a[i+1]){
            lst = a[i];
        }
    }
    for(int i = 2; i < n; i++){
        if(a[i] >= a[i-1] && a[i] >= a[i+1]){
            ans = max(ans, min(a[i] - pre[i], a[i] - suf[i]));
        }
    }
    cout << ans << endl;
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