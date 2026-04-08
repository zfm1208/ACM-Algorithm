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
    int n,m; cin >> n >> m;
    // vector<set<int>> mp(m+1);
    // 优化使用vector
    vector<vector<int>> mp(m+1);
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        rep(j,1,k){
            int x; cin >> x;
            // mp[x].insert(i);
            mp[x].pb(i);
        }
    }
    int q; cin >> q;
    while(q--){
        int a,b; cin >> a >> b;
        int cnt = 0;
        // if(mp[a].size() < mp[b].size()){
        //     for(int x: mp[a]){
        //         if(mp[b].find(x) != mp[b].end()){
        //             cnt++;
        //         }
        //     }            
        // }else{
        //     for(int x: mp[b]){
        //         if(mp[a].find(x) != mp[a].end()){
        //             cnt++;
        //         }
        //     }              
        // }

        // 双指针优化
        int i = 0,j = 0;
        while(i < mp[a].size() && j < mp[b].size()){
            if(mp[a][i] == mp[b][j]){
                cnt++;
                i++,j++;
            }else if(mp[a][i] < mp[b][j]){
                i++;
            }else{
                j++;
            }
        }
        cout << cnt << endl;
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