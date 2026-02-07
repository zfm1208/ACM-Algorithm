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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve(){
    int n; cin >> n;
    vector<pii> a(n+1);
    vector<int> vis(n+2);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin()+1,a.end(),[](pii x, pii y){
        return x.fi > y.fi;
    });
    int ans = 0;
    for(int i = 1; i <= n;){
        int j = i;
        while(j <= n && a[j].fi == a[i].fi){
            j++;
        }
        // [i,j-1] 值相同
        vector<int> b;
        for(int q = i; q < j; q++) b.pb(a[q].se);
        sort(b.begin(),b.end());
        if(b.size()){
            int st = b.front();
            int ed = b.front();
            for(int k = 1; k < b.size(); k++){
                if(b[k] == ed+1){
                    ed++;
                }else{
                    if(!vis[st-1] && !vis[ed+1]) ans++;
                    st = ed = b[k];
                }
            }
            if(!vis[st-1] && !vis[ed+1]) ans++;
        }
        for(auto x : b) vis[x] = 1;
        i = j;
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