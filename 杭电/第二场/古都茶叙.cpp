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
    vector<int> a(n+1),b(2*n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    b[0] = a[0] = -1;
    for(int i = 1; i <= 2*n; i++){
        if(i <= n) b[i] = a[i];
        else b[i] = a[i-n];
        if(b[i] >= 0 && b[i-1] < 0 && i <= n) {
            ans.pb(i);
        }
    }
    for(auto x: ans){
        int pre = 0;
        for(int i = x; i < x+n; i++){
            pre += b[i];
            if(pre < 0) break;
        }
        if(pre >= 0) {
            cout << x << endl;
            return;
        }
    }
    
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