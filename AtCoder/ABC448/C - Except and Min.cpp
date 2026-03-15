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
    int n,q; cin >> n >> q;
    vector<pii> a(n+1);
    rep(i,1,n) cin >> a[i].fi, a[i].se = i;
    sort(a.begin()+1,a.end());
    while(q--)
    {
        int k; cin >> k;
        vector<int> b(k+1);
        rep(i,1,k) cin >> b[i];
        for(int i = 1; i <= k+1; i++){
            bool ok = 0;
            for(int j = 1; j <= k; j++){
                if(a[i].se == b[j]){
                    ok = 1;
                    break;
                }
            }
            if(!ok){
                cout << a[i].fi << endl;
                break;
            }
        }
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