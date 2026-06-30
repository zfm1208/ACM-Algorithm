#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
// vector<int> cun;
set<int> cun;
void init(){
    auto dfs = [&](auto&& self, int x, int i, int j) -> void {
        if(x > 1e9) return;
        if(x >= 2) cun.insert(x);
        self(self, x * 10 + i, i, j);
        self(self, x * 10 + j, i, j);
    };
    
    for(int i = 0; i < 10; i++){
        for(int j = i; j <= 9; j++){
            dfs(dfs, 0LL, i, j);
        }
    }

}
void solve(){
    // int x; cin >> x;
    // for(int y: cun){
    //     set<int> st;
    //     int ts = x * y;
    //     while(ts){
    //         st.insert(ts % 10);
    //         ts/=10;
    //     }
    //     if(st.size() == 1){
    //         cout << y << endl;
    //         return;
    //     }
    // }
    string x; cin >> x;
    int y = 1;
    for(int i = 0; i < x.size(); i++){
        y *= 10;
    }
    y++;
    cout << y << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}