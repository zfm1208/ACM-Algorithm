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
    map<int,vector<pii>> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] -= i;
        mp[a[i]].pb({a[i]+i,i});
    } 
    int ans = 0;
    for(auto &[x,ar]: mp){
        sort(ar.begin(),ar.end(),[](pii x,pii y){
            return x.fi > y.fi;
        });
        if(ar.size() == 1) continue;
        for(int i = 0; i < ar.size(); i+=2){
            if(i+1>=ar.size()) continue;
            int sum = ar[i].fi + ar[i+1].fi;
            if(sum > 0){
                ans += sum;
            }
        }
    }
    cout << ans << endl;
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