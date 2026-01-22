#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a;
    rep(i,1,n){
        int x;cin >> x;
        a.pb(x);
    }
    int ans = 0;
    while(a.size() > 1){
        vector<int> cun;
        int sz = a.size();
        if(a[0] > a[1]) cun.pb(a[0]);
        for(int i = 1; i < sz - 1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                cun.pb(a[i]);
            }
        }
        if(a[sz-1] > a[sz-2]) cun.pb(a[sz-1]);
        if(cun.size() == a.size()){
            break;
        }
        ans++;
        a = cun;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}