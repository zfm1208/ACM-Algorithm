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
    int head, n; cin >> head >> n;
    vector<int> vis(N), nxt(N), val(N);
    for(int i = 1; i <= n; i++){
        int dz, x, dz1;
        cin >> dz >> x >> dz1;
        val[dz] = x;
        nxt[dz] = dz1;
    }
    vector<int> ans,ans1;
    int cur = head;
    while(cur != -1){
        if(!vis[abs(val[cur])]){
            vis[abs(val[cur])] = 1;
            ans.pb(cur);
        }else{
            ans1.pb(cur);
        }
        cur = nxt[cur];
    }
    cout << setfill('0');
    for(int i = 0; i < ans.size(); i++){
        if(i != ans.size() - 1){
            cout << setw(5) << ans[i] << " "  << val[ans[i]] << " "  << setw(5) << ans[i+1] << endl;
        } else{
            cout << setw(5) << ans[i] << " "  << val[ans[i]] << " -1" << endl;
        }
    }
    for(int i = 0; i < ans1.size(); i++){
        if(i != ans1.size() - 1){
            cout << setw(5) << ans1[i] << " "  << val[ans1[i]] << " "  << setw(5) << ans1[i+1] << endl;
        } else{
            cout << setw(5) << ans1[i] << " "  << val[ans1[i]] << " -1" << endl;
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