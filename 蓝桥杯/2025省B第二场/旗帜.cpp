#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int h,w; cin >> h >> w;
    string s = "lanqiao";
    int n = s.size();
    string ss = "";
    int cnt = 0;
    for(int i = 0; i < w; i++){
        ss += s[i%n];
    }
    int op = w;
    for(int i = 1; i <= h; i++){
        for(int j = 0; j < w; j++){
            if(ss[j] == 'a') cnt++;
        }
        ss = ss.substr(1);
        ss += s[op%n];
        op++;
    }
    cout << cnt;
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