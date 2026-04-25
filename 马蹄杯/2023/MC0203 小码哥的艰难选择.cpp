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
    vector<pair<string,int>> a(n+1);
    map<string,int> mp;
    rep(i,1,n){
        cin >> a[i].fi >> a[i].se;
        mp[a[i].fi] += a[i].se;
    }
    int mn = inf;
    for(auto&[s,x] : mp){
        mn = min(mn, x);
    }
    map<string,int> cur;
    for(int i = 1; i <= n; i++){
        auto& [s,x] = a[i];
        cur[s] += x;
        if(mp[s] == mn){ // 必须要加这个,可看下面样例,不加的话输出的是A,但答案其实是B
            if(cur[s] <= mn){
                cout << s << endl << 1000 + mn << endl;
                return;
            }
        }
    }

}
/*
    3
    A -10  第一回合
    B -50  第二回合  ans！  
    A -40  第三回合
*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}