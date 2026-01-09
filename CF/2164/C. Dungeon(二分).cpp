#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
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
void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    vector<pii> b(m+1);
    priority_queue<int,vector<int>,greater<int>> q,q1,is0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        q.push(a[i]);
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i].first;
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i].second;
        if(b[i].second == 0){
            is0.push(b[i].first);
            b[i].fi = inf;
        }
    }
    sort(b.begin()+1,b.begin()+1+m,[](auto x, auto y){
        if(x.fi == y.fi) return x.se > y.se;
        return x.fi < y.fi;
    });
    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(b[i].fi == inf) break;
        while(!q.empty() && q.top() < b[i].first){
            q1.push(q.top());
            q.pop();
        }
        if(q.empty()) break;
        int tp = q.top();
        q.pop();
        q.push(max(tp,b[i].second));
        ans++;
    }
    while(!q.empty()){
        q1.push(q.top());
        q.pop();
    }
    while(!q1.empty() && !is0.empty()){
        if(q1.top() < is0.top()){
            q1.pop();
        }else{
            q1.pop();
            is0.pop();
            ans++;
        }
    }
    cout << ans << endl; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}