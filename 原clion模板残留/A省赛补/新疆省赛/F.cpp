#include<bits/stdc++.h>
using namespace  std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define fi first
#define se second
void solve(){
    int n,k; cin >> n >> k;
    vector<pair<pii,int>> a(n+1);
//    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        int pi,vi; cin >> pi >> vi;
        a[i]={{pi,vi},i};
    }
    vector<int> c(n+1);
    for(int i = 1; i <= n; i++){
        c[i] = a[i].fi.fi + a[i].fi.se * k;
    }
    sort(c.begin()+1,c.end());
    vector<int> ans(n+1);
    sort(a.begin()+1,a.begin()+1+n,[](pair<pii,int> x,pair<pii,int> y){
        return x.fi.fi < y.fi.fi;
    });
    for(int i =1; i <= n; i++){
        ans[a[i].se] = c[i];
    }
    for(int i=1; i<= n;i++){
        cout << ans[i] << " \n"[i==n];
    }
    // end_pos == pi + vi * k;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}