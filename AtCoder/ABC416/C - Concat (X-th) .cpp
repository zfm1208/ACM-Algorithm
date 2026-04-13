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
    int n,k,x; cin >> n >> k >> x;
    vector<string> s(n+1);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    vector<string> ans;
    auto dfs = [&](auto& self, int dep, string T) -> void {
        if(dep > k){
            ans.push_back(T);
            return;
        }
        for(int i = 1; i <= n; i++){
            self(self, dep+1, T + s[i]);
        }
    };
    dfs(dfs,1,"");
    sort(ans.begin(),ans.end());
    cout << ans[x-1] << endl;
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