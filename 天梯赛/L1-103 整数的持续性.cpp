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
    int a,b; cin >> a >> b;
    map<int,vector<int>> mp;
    auto check = [&](int x) -> int {
        int cnt = 0;
        while(x > 10){
            cnt++;
            int tp = 1;
            while(x){
                tp*=(x%10);
                x/=10;
            }
            x = tp;
        }
        return cnt;
    };
    int mx = 0;
    for(int i = a; i <= b; i++){
        int op = check(i);
        mp[op].pb(i);
        mx = max(mx,op);
    }
    sort(mp[mx].begin(),mp[mx].end());
    cout << mx << endl;
    for(int i = 0; i < mp[mx].size(); i++){
        if(i == mp[mx].size() - 1){
            cout << mp[mx][i];
        }else{
            cout << mp[mx][i] << " ";
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