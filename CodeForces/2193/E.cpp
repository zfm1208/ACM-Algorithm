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
    vector<int> a(n+1),b;
    map<int,int> mp;
    rep(i,1,n) cin >> a[i],mp[a[i]]++;
    vector<int> ans(n+1,-1);
    rep(i,1,n) if(mp.count(i)) ans[i] = 1;
    for(auto[x,_] : mp) b.pb(x);
    queue<int> q;
    for(auto x : b) q.push(x);
    while(q.size()){
        int u = q.front();q.pop();
        for(auto v: b){
            if(u * v > n) break;
            if(ans[u * v] == -1){
                ans[u * v] = ans[u] + 1;
                q.push(u * v);
            }
        }
    }
    rep(i,1,n) cout << ans[i] << " \n"[i==n];
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