#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10,mod = 1e9+7;
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)

void zfm(){
    int n,m; cin >> n >> m;
    vector<pii> c(n+1);
    vector<int> b(n+1);
    int xf = 0;
    for(int i = 1; i <= n; i++){
        cin >> c[i].first >> c[i].second;
        xf += c[i].first;
        b[i] = (c[i].second - c[i].first);
    }
    int ans = 0;
    sort(b.begin()+1,b.end(),[](int x, int y){
        return x > y;
    });
    int pre = 0;
    for(int i = 0; i <= n; i++){
        pre += b[i];
        int k = i, rk = n - k;
        bool ok = 0;
        if(rk == 0){
            if(m >= 2*n-1) ok = 1;
        }else{
            if(rk > 1){
                if(m >= 2*k + (n-k)){
                    ok = 1;
                }
            }
        }
        if(ok){
            ans = max(ans,pre + xf);
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        zfm();
    }
    return 0;
}