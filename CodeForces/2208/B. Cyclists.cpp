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
    int n,k,p,m; 
    cin >> n >> k >> p >> m;
    vector<int> a(n+1);
    vector<pii> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int op = i == p;
        q.pb({a[i],op});
    }
    int ans = 0;
    while(1){
        int pos = -1;
        for(int i = 0; i < k; i++){
            auto [x,ok] = q[i];
            if(ok){
                pos = i;
                break;
            }
        }
        if(pos != -1){
            if(m - q[pos].fi < 0) break;
            ans++;
            m -= q[pos].fi;
            pii temp = q[pos];
            q.erase(q.begin()+pos);
            q.pb(temp);
        }else{
            int mn = inf;
            int id = 0;
            for(int i = 0; i < k; i++){
                if(q[i].fi < mn){
                    mn = q[i].fi;
                    id = i;
                }
            }
            if(m - mn < 0) break;
            m -= mn;
            pii temp = q[id];
            q.erase(q.begin()+id);
            q.pb(temp);
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