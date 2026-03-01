#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> c(n+1);
    rep(i,1,n) cin >> c[i];
    int ans = 0;
    vector<int> a;
    int op = 0;
    for(int i = n; i >= 1; i--){
        if(c[i] != c[1]){
            op = i;
            break;
        }
    }
    a.push_back(-1);
    for(int i = op+1; i <= n; i++){
        a.push_back(c[i]);
    }
    for(int i = 1; i <= op; i++){
        a.push_back(c[i]);
    }
    int l = 1,r = 1;
    int mx = 0;
    while(l <= n){
        while(r <= n && a[r] == a[l]) r++;
        int cnt = r - l;
        mx = max(mx,cnt);
        ans += (cnt + k- 1 )/ k;
        l = r;
    }
    if(mx >= k){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}