#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7, base = 131;
#define pb push_back
void solve(){
    vector<array<int,3>> p(8);
    map<array<int,3>,int> mp;
    for(int i = 0; i < 8; i++){
        int x,y,z; cin >> x >> y >> z;
        p[i] = {x,y,z};
        mp[p[i]]++;
    }
    for(auto [_,x] : mp){
        if(x > 1){
            cout << "NO" << endl;
            return;
        }
    }
    vector<int> d;
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 8; j++){
            auto [x,y,z] = p[i];
            auto [x1,y1,z1] = p[j];
            int dist = (x-x1) * (x-x1) + (y - y1) * (y - y1) + (z-z1) * (z-z1);
            d.pb(dist);
        }
    }
    sort(d.begin(),d.end());
    bool ok = 0;
    for(int i = 0; i < 12; i++){
        if(d[i] != d[0]){
            cout << "NO" << endl;
            return;            
        }
    }
    for(int i = 12; i < 24; i++){
        if(d[i] != 2 * d[0]){
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 24; i < 28; i++){
        if(d[i] != 3 * d[0]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}