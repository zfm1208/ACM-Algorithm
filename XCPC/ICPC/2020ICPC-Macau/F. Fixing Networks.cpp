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
const int N = 1e6, mod = 98244353, inf = 1e18 + 5;

void solve(){
    int n,d,c; cin >> n >> d >> c;
    if(c * (d + 1) > n || (n % 2 == 1 && d % 2 == 1)) {
        cout << "No" << endl;
        return;
    }
    if(d == 0){
        if(c == n) {
            cout << "Yes" << endl;
            for(int i = 1; i <= n; i++){
                cout << endl;
            }
        }else{
            cout << "No" << endl;
        }
        return;
    }
    if(d == 1){
        if(n == 2 * c){
            cout << "Yes" << endl;
            for(int i = 1; i <= n; i++){
                if(i & 1) cout << i + 1 << endl;
                else cout << i-1 << endl;
            }
        }else{
            cout << "No" << endl;
        }
        return;
    }
    
    cout << "Yes" << endl;
    vector<vector<int>> adj(n+1);
    int st = 1;
    for(int i = 1; i <= c-1; i++){
        for(int u = st; u <= st + d; u++){
            for(int v = st; v <= st + d; v++){
                if(u != v) adj[u].pb(v);
            }
        }
        st += d + 1;
    }

    int m = n - st + 1;
    for(int i = 0; i < m; i++){
        int u = st + i;
        for(int j = 1; j <= d/2; j++){
            int x1 = st + (i + j) % m;
            int x2 = st + (i - j + m) % m;
            adj[u].pb(x1);
            adj[u].pb(x2);
        }
        if(d & 1){
            int x3 = st + (i + m / 2) % m;
            adj[u].pb(x3);
        }
    }
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
        for(int x : adj[i]) cout << x << " ";
        cout << endl;
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