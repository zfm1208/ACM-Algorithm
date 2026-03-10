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
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        int len; cin >> len;
        a[i].resize(len);
        for(auto &x: a[i]) cin >> x;
        reverse(a[i].begin(),a[i].end());
        vector<int> tp;
        for(int j = 0; j < len; j++){
            if(find(tp.begin(),tp.end(),a[i][j]) == tp.end()){
                tp.pb(a[i][j]);
            }
        }
        a[i] = tp;
    }
    vector<int> vis(n);
    vector<int> ans;
    for(int t = 0; t < n; t++){
        int op = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (op == -1 || a[i] < a[op])){
                op = i;
            }
        }
        vis[op] = 1;
        for(auto x: a[op]){
            ans.pb(x);
            for(int i = 0; i < n; i++){
                if(vis[i]) continue;
                auto it = find(a[i].begin(),a[i].end(),x);
                if(it != a[i].end()){
                    a[i].erase(it);
                }
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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