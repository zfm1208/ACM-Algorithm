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
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].se;
    }
    auto check = [&](int x) -> bool {
        multiset<int> s[2];
        for(int i = 1; i <= n; i++){
            auto [ai, c] = a[i];
            auto it = s[1-c].lower_bound(x-ai);
            if(s[1-c].size() == 0){
                s[c].insert(ai);
            }
            else if(it != s[1-c].end()){
                s[1-c].erase(it);
            }else{
                return false;
            }
        }
        return true;
    };
    int l = 0,r = inf;
    int ans = -1;
    while(l <= r){
        int mid  = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << endl;
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