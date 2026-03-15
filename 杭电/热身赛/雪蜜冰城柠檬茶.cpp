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
/*
    1>: 将数列所有 x -> y
    2>: 数列末尾加上一个 x
    3>：将数列所有的 x 踢出
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    unordered_map<int,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]].pb(i);
    }
    int q; cin >> q;
    int cnt = n;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x,y; cin >> x >> y;
            if(x==y) continue;
            for(auto id: mp[x]){
                mp[y].pb(id);
            }
            mp[x].clear();
        }else if(op == 2){
            int x; cin >> x;
            mp[x].pb(++cnt);
        }else{
            int x; cin >> x;
            if(mp.count(x)) mp[x].clear();
        }
    }
    vector<pii> ans;
    for(auto [x,ar] : mp){
        for(int id: ar){
            ans.pb({id,x});
        }
    }
    sort(ans.begin(),ans.end());
    for(auto [id,x]: ans){
        cout << x << " ";
    }
    cout << endl;
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