#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = LLONG_MAX;
void ff(){
    int n,x,y; cin >> n >> x >> y;
    vector<int> a(n+1),b,c;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] <= n){
            b.push_back(a[i]);
            mx = max(mx,a[i]);
        }else{
            c.push_back(a[i]);
        }
    }
    int nb = b.size();
    int nc = c.size();
    map<int,int> mpc;
    int cntc = 0;
    for(int i = 0; i < c.size(); i++){
        mpc[c[i]]++;
        cntc = max(cntc,mpc[c[i]]);
    }
    int ans = (n - cntc) * y;
    int ans1 = (mx * x) + nc * y;
    ans = min(ans , ans1);
    int mxb=0;
    map<int,int> mp1;
    for(int i = 0; i < b.size(); i++){
        mp1[b[i]]++;
        if(mp1[b[i]] > mxb){
            mxb = mp1[b[i]];
        }
    }
    int ans2 = (nb - mxb) * y + nc * y ;
    ans = min(ans,ans2);
    int anss = inf;
    vector<int>pre(n+1);
    int sum = 0;
    int res = inf;
    for(auto [f,q]: mp1){
        sum += q;
        res = min(res, f * x + (nb - sum) * y);
    }
    res += nc * y;
    ans = min(ans,res);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        ff();
    }
    return 0;
}