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
// https://ac.nowcoder.com/acm/contest/130418/I
void solve(){
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    set<vector<int>> st;
    vector<int> cun;
    auto dfs = [&](auto & self, int i, int j) -> void {
        if(i == n && j == n){
            st.insert(cun);
            return;
        }
        if(i < n){
            cun.pb(a[i+1]);
            self(self,i+1,j);
            cun.pop_back();
        }
        if(j < n){
            cun.pb(b[j+1]);
            self(self,i,j+1);
            cun.pop_back();
        }
    };
    dfs(dfs,0,0);
    cout << st.size() << endl;
    for(auto &arr : st){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " \n"[i == arr.size() - 1];
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