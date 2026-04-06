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
    map<int,set<int>> mp;
    for(int i = 1; i <= n; i++){
        int m; cin >> m;
        while(m--){
            int x; cin >> x;
            mp[i].insert(x);
        }
    }
    int q; cin >>q;
    while(q--){
        int a,b; cin >> a >> b;
        double ans;
        int cnt = 0;
        set<int> tp = mp[b];
        for(auto &x: mp[a]){
            if(mp[b].find(x) != mp[b].end()){
                cnt++;
            }else{
                tp.insert(x);
            }
        }
        int tot = tp.size();
        ans = cnt * 100.0 / tot;
        cout << fixed << setprecision(2) << ans << "%" << endl;        
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}