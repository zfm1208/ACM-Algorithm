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
    map<int,int> mp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    bool ok = 0;
    vector<int> bi,d;
    int cnt = 0;
    for(auto [x,y]: mp){
        if(y >= 4){
            ok = 1;
            rep(i,1,4) cout << x << " ";
            cout << endl;
            return;
        }
        if(y >= 2){
            ok = 1;
            bi.pb(x);
            if(y > 2){
                d.pb(x);
            }
        }else{
            d.pb(x);
        }
    }
    if(!ok){cout << -1 << endl; return;}
    if(bi.size() >= 2){
        cout << bi[0] << " " << bi[0] << " " << bi[1] << " " << bi[1] << endl;
        return;
    }
    sort(bi.begin(),bi.end());
    sort(d.begin(),d.end());
    int mx = bi[bi.size()-1];
    for(int x: d){
        int sum = x + mx*2;
        auto it = lower_bound(d.begin(),d.end(),sum);
        it--;
        if(it == d.end()) continue;
        if(*it > x){
            cout << *it << " " << x << " " << mx << " " << mx << endl;
            return;
        }
    }
    cout << -1 << endl;
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