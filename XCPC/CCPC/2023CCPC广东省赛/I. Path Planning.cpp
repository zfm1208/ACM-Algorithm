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
    int n, m;
    cin >> n >> m;
    
    vector<pii> pos(n * m);
    rep(i, 1, n) rep(j, 1, m){
        int x; cin >> x;
        pos[x] = {i, j};
    }
    
    
    auto check = [&](int k) {
        if (k <= 1) return true; 
        
        vector<pii> p(k);
        for(int i = 0; i < k; i++){
            p[i] = pos[i];
        }
        
        sort(p.begin(), p.end());
        
        for(int i = 1; i < k; i++){
            if(p[i].se < p[i - 1].se){
                return false;
            }
        }
        return true;
    };
    
    int l = 0, r = n * m;
    int ans = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)){
            ans = mid;   
            l = mid + 1;
        } else {
            r = mid - 1;  
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