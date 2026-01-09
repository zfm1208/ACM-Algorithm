#include<bits/stdc++.h>
using namespace  std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int N = 1e6+5;
#define pii pair<int,int>
#define fi first
#define se second
//j
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int ans = 0;
    int mx = 0;
    map<int,int> mp;
    while(n--){
        int x;cin >> x;
        mp[x]++;
    }
//    rep(i,1,n) cin >> a[i], mx = max(mx, a[i]), mp[a[i]]++;
    if(n==1){
        cout << 0 << '\n';
        return;
    }
    vector<int> v(N,0);
    for(int i=1;i<=n;i++) v[a[i]]++;
    int cnt = 0;
//    for(auto it = mp.begin();it!=mp.end();it++) cout << it->first << ' ' << it->second << '\n';
//    for(int i=1;i<=mx;i++){
//        if(v[i]>0){
//            if(v[i/2] > 0 && i % 2 == 0){
//                cnt += min(mp[i],mp[i/2]);
//                v[i]-= min(mp[i],mp[i/2]);
//                v[i/2] -= min(mp[i],mp[i/2]);
////                if(i*2<=mx){
////                    v[i*2] -= min(mp[i],mp[i/2]);
////                    v[i*2] = max(0ll,v[i*2]);
////                }
//            }
////            else if(v[i] == 1 && v[i*2]==1){
////                cnt++;
////                v[i]=0;
////                v[i*2] = 0;
////            }
//        }
//    }
//    cout << cnt << '\n';
//    int n;cin >> n;
//    map<int,int>mp;

    vector<pii> dp(N);
    for(int i=1;i<=N;i++){
        if(i%2==0){
            dp[i].se = dp[i/2].fi;
            dp[i].fi = min(dp[i/2].fi,dp[i/2].se)+mp[i];
        }
        else{
            dp[i].fi=mp[i];
            dp[i].se=0;
        }
    }
    for(int i=1;i<=N;i++){
        if(i*2>N)ans+=min(dp[i].fi,dp[i].se);
    }
    cout << ans << '\n';
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
//6
//2 4 8 8 16 16
// 3

//10
//2 2 2 4 4 8 8 16 16 16
//4

//10
//2 2 4 4 8 8 16 32 32 64
//4
//  4 4 16 64