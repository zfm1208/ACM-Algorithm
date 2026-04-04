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
vector<int> pri;
vector<int> vis(N);
void init(){
    vis[0] = vis[1] = 1;
    for(int i = 2; i < N; i++){
        if(vis[i] == 0) pri.pb(i);
        for(int j = 0; j < pri.size() && i * pri[j] < N; j++){
            vis[i*pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}
/*
    2 3 5 7 11 13

    2 6 15 35 77  143

     2  3  5  7  11
*/
void solve(){
    int n; cin >> n;
    cout << pri[0] << " ";
    for(int i = 1; i < n-1; i++){
        int x = pri[i] * pri[i-1];
        cout << x << " ";
    }
    cout << pri[n-2] << " \n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}